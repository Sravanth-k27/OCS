#include <iostream>
#include <fstream>
#include <string.h>
#include <random>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <limits.h>
#include <sys/time.h>
using namespace std;

int n_w,n_r,k_w,k_r;    //variables for storing no of writer,reader threads & no of times they access the CS.

float mu_cs , mu_rem ;  //variables for storing mu_cs & mu_rem

int read_count =0;      //intializing readers count as 0

sem_t mutex , rw_mutex ;  //semaphores 

double writer_waiting_time = 0 ;  //variable for caluclating total writers waiting time

double reader_waiting_time = 0 ;  //variable for caluclating total readers waiting time

double max_writer_waiting_time = INT_MIN ;  //variable for worst writer waiting time

double max_reader_waiting_time = INT_MIN;   //variable for worst reader waiting time

ofstream output_file_1;   //output file for printing data

//This function returns the system time as a string  by taking time_t variable as argument

string get_system_time(time_t mytime){

    string a=  ctime(&mytime);

    return a.substr(11,8);
}

//Writers code

void * writer (void * id){

    int thread_id = (long) id ; //storing parameter as thread_id

    default_random_engine random ;  //This takes the role of assigining random variables

    exponential_distribution<double>cs_time(1/mu_cs); //Declaring cs_time as exponential distribution with mean as mu_cs

    exponential_distribution<double>rem_time(1/mu_rem);  //Declaring rem_time as exponential distribution with mean as mu_rem

    //Each writer thread will enter CS k_w times

    for (int i=0;i<k_w;i++){

        struct timeval req_time; //declaration of request time.

        gettimeofday(&req_time,NULL); //caluclation of system time when the threads makes request to enter CS.

        string req_time_string = get_system_time(req_time.tv_sec); //caluclation of request time as string

        sem_wait(&rw_mutex);  //acquring the lock 

        //ENTRY section

        struct timeval enter_time ; //declaration of entry time

        gettimeofday(&enter_time,NULL); //caluclation of system time when the threads enters the entry section

        string enter_time_string = get_system_time(enter_time.tv_sec); //caluclation of entry time as string

        //printing the request & entry of a thread to the output file

        output_file_1 << i+1 << " th CS Request by Writer thread "<<thread_id<<" at "<<req_time_string<<"\n";

        output_file_1 << i+1 << " th CS Entry by Writer thread "<<thread_id<<" at "<<enter_time_string<<"\n";

        //caluclating waiting time of each thread

        double wait=(enter_time.tv_sec-req_time.tv_sec)*1e6+(enter_time.tv_usec-req_time.tv_usec);

        //calucalting total waiting time of all writers.

        writer_waiting_time=writer_waiting_time+wait;

        //caluclating maximum writer waiting time.

        max_writer_waiting_time=max(max_writer_waiting_time,wait);

        //CRITICAL section

        random.seed(thread_id*n_w+i); //seed intialization

        usleep(cs_time(random)*1e3); //simulation of CRITICAL section

        //EXIT section

        struct timeval exit_time ; //declaration of exit time

        gettimeofday(&exit_time,NULL); //caluclation of system time when thread is in exit section

        string exit_time_string = get_system_time(exit_time.tv_sec); //caluclation of exit time as a string

        output_file_1 << i+1 << " th CS Exit by Writer thread " <<thread_id<<" at "<<exit_time_string<<"\n";

        sem_post(&rw_mutex);  //releasing the lock

        random.seed(thread_id*n_w+i); //seed intialization

        usleep(rem_time(random)*1e3); //simulation of REMAINDER section


    }
    
    pthread_exit(0);

}

void *reader (void * id){

    int thread_id= (long) id ;  //storing parameter as thread_id

    default_random_engine random ;    //This takes the role of assigining random variables

    exponential_distribution<double>cs_time(1/mu_cs);  //Declaring cs_time as exponential distribution with mean as mu_cs

    exponential_distribution<double>rem_time(1/mu_rem);  //Declaring rem_time as exponential distribution with mean as mu_rem

    //Each reader thread will enter CS k_r times

    for (int i=0;i<k_r;i++){

        struct timeval req_time;  //declaration of request time.

        gettimeofday(&req_time,NULL);  //caluclation of system time when the threads makes request to enter CS.

        string req_time_string = get_system_time(req_time.tv_sec);  //caluclation of request time as string

        sem_wait(&mutex); //acquring the lock for increasing readers count

        read_count++;   //increasing readers count

        //cout <<"Readers count is :"<<read_count<<"\n";

        //If the first reader arrives acquire the resource for the readers

        if (read_count==1){

            sem_wait(&rw_mutex);  //acquirng the resource
        }
        
        //ENTRY section

        struct timeval enter_time ;  //declaration of entry time

        gettimeofday(&enter_time,NULL);  //caluclation of system time when the threads enters the entry section

        string enter_time_string= get_system_time(enter_time.tv_sec);  //caluclation of entry time as string

        //printing request & entry of a thread to output file

        output_file_1 << i+1 << " th CS Request by Reader thread "<<thread_id<<" at "<<req_time_string<<"\n";

        output_file_1 << i+1 << " th CS Entry by Reader thread "<<thread_id<<" at "<<enter_time_string<<"\n";

        //caluclating waiting time of each thread

        double wait=(enter_time.tv_sec-req_time.tv_sec)*1e6+(enter_time.tv_usec-req_time.tv_usec);

        //caluclating total readers waiting time.

        reader_waiting_time=reader_waiting_time+wait;

        //caluclating maximum reader waiting time.

        max_reader_waiting_time=max(max_reader_waiting_time,wait);

        sem_post(&mutex);  //releasing the lock

        //CRITICAL section

        random.seed(thread_id*n_r+i);  //seed intiailization

        usleep(cs_time(random)*1e3);   //simulation of CRITICAL section

        //cout <<"Readers count is :"<<read_count<<"\n";

        sem_wait(&mutex);  //acquiring lock for decreasing readers count 

        read_count--;    //decreasing readers count

        //If readers count is 0 free the resource and give resource to the writers.

        if (read_count==0){

            sem_post(&rw_mutex);
        }

        //EXIT section

        struct timeval exit_time ;  //declaration of exit time

        gettimeofday(&exit_time,NULL);    //caluclation of system time when thread is in exit section

        string exit_time_string = get_system_time(exit_time.tv_sec);  //caluclation of exit time as a string

        //printing exit of a thread to the output file

        output_file_1 << i+1 << " th CS Exit by Reader thread " <<thread_id<<" at "<<exit_time_string<<"\n";

        sem_post(&mutex);  //releasing lock

        random.seed(thread_id*n_r+i); //seed initialization

        usleep(rem_time(random)*1e3); //simulation of REMAINDER section

    }

    pthread_exit(0);

}



int main(){

    ifstream input_file("inp-params.txt");

    input_file>>n_w>>n_r>>k_w>>k_r>>mu_cs>>mu_rem; //scanning the values from input file

    output_file_1.open("RW-log.txt");

    ofstream output_file_2;

    output_file_2.open("Average_time.txt",ios::app);

    pthread_t writer_tid[n_w]; //declaration of thread id for writer threads

    pthread_t reader_tid[n_r]; //declaration of thread id for reader threads

    //semaphore intializations

    sem_init (&mutex,0,1);

    sem_init (&rw_mutex,0,1);

    cout << "The Reader & Writer threads are being accessing the CS.Once the program finishes it's execution check the RW-log.txt , Average_time.txt files for the output\n";

    //creating writer threads

    for (int i=0;i<n_w;i++){

        pthread_create(&writer_tid[i],NULL,writer,(void *) (long) (i+1));

    }
    
    //creating reader threads

    for (int i=0;i<n_r;i++){

        pthread_create(&reader_tid[i],NULL,reader,(void*)(long) (i+1));

    }

    //joining writer threads

    for (int i=0;i<n_w;i++){

        pthread_join(writer_tid[i],NULL);

    }
    
    //joining reader threads

    for (int i=0;i<n_r;i++){

        pthread_join(reader_tid[i],NULL);

    }

    //cout << n_w <<" "<< n_r <<" " << k_w << " " << k_r << " "<<mu_cs<<" "<<mu_rem<<"\n";

    float average_writer_waiting_time = (writer_waiting_time)/(n_w*k_w*1e3);

    float average_reader_waiting_time = (reader_waiting_time)/(n_r*k_r*1e3);

    float total_waiting_time = (writer_waiting_time+reader_waiting_time)/(n_w*k_w*1e3+n_r*k_r*1e3);

    float worst_writer_waiting_time = max_writer_waiting_time/1e3;

    float worst_reader_waiting_time = max_reader_waiting_time/1e3;

    output_file_2 << "\nRW-Algorithm Analysis : \n";

    output_file_2 << "\nWorst Waiting times :\n";

    output_file_2 << "\nWorst waiting time of writer threads is : "<<worst_writer_waiting_time<<" milliseconds\n";

    output_file_2 << "Worst waiting time of reader threads is : " <<worst_reader_waiting_time<<" milliseconds\n";

    output_file_2 << "\nAverage Waiting times :\n";

    output_file_2 << "\nThe average waiting time of writer threads is : "<<average_writer_waiting_time<<" milliseconds\n";

    output_file_2 << "The average waiting time of reader threads is : "<<average_reader_waiting_time<<" milliseconds\n";

    output_file_2 << "The total average waiting time of a thread is : "<<total_waiting_time<<" milliseconds\n";

    cout <<"Check the RW-log.txt & Average_time.txt files for the output\n";


    input_file.close();

    output_file_1.close();

    output_file_2.close();

    return 0;
}