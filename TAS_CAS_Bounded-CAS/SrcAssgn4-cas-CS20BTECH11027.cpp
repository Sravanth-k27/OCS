#include <iostream>
#include <pthread.h>
#include <fstream>
#include <time.h>
#include <atomic>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <random>
using namespace std;

int n,k;  //variables for storing no of threads & no of times a thread enters the CS.

float lambda_one,lambda_two ;   //Variables for stoting the values of lambda 1 , lambda 2 .

std::ofstream output_file ;     //output_file for printing the data.

time_t waiting_time = 0 ;       //variable for caluclating waiting time for all the threads which was intialized as 0.

time_t max_waiting_time = INT_MIN ;   //variable for caluclating maximum waiting time of a thread to enter CS.

//This function returns the system time as a string  by taking time_t variable as argument 

string get_system_time(time_t mytime){

    string a=  ctime(&mytime);

    return a.substr(11,8);
}

atomic<int> lock; //atomic lock for compare and swap instruction 

//this is the function which is executed by all the threads.

void *testCS(void * id){

    int thread_id = (long)id;    //storing parameter as the thread id .

    default_random_engine random ;  //this takes the role of assigining random values .

    exponential_distribution<double>t1(1.0/lambda_one);   //Declaring t1 as the exponential distribution with mean lambda_one.

    exponential_distribution<double>t2(1.0/lambda_two);   //Declaring t2 as the exponential distribution with mean lambda_two.

    //Each thread will enter the CS k times .

    for (int i=0;i<k;i++){

        time_t req_enter_time = time (NULL);   //caluclation of system time when a thread makes a request .

        string req_enter_time_string = get_system_time(req_enter_time);  //caluclation of system time as a string

        //variables for executing the compare and swap instruction 
        
        int x=0;

        int y=1;

        while(!lock.compare_exchange_strong(x,y)){

            x=0;

            y=1;

        } //BUSY waiting 

        //ENTRY section

        time_t act_enter_time = time (NULL);  //caluclation of system wait at ENTRY section

        string act_enter_time_string = get_system_time(act_enter_time);  //caluclation os sytem time as a string

        //caluclation of total waiting times of all threads by assing waiting times of each thread.

        waiting_time = waiting_time + (act_enter_time-req_enter_time);

        //caluclation of maximum waiting time of a thread to enter the CS 

        max_waiting_time=max(max_waiting_time,act_enter_time-req_enter_time);

        //CRITICAL section

        usleep(t1(random)*1e6);  //Simulation of CRITICAL section 

        //printing the request and entry of threads to the output file 

        output_file<<i+1<<"th CS Request at "<<req_enter_time_string<<" by thread "<<thread_id<<"\n";

        output_file<<i+1<<"th CS Entry at "<<act_enter_time_string<<" by thread "<<thread_id<<"\n";

        //EXIT section 

        time_t exit_time = time (NULL);  //caluclation of system time at EXIT section 

        string exit_time_string = get_system_time(exit_time);  //caluclation of system time as a string 

        //printing the exit of a thread to the output file.

        output_file<< i+1<<"th Exit at "<<exit_time_string<<" by thread " << thread_id<<"\n";

        lock=0; //declaring lock as 0 so that it is madde available to other threads who are in busy waiting

        //REMAINDER section

        usleep(t2(random)*1e6);  //Simulation of Remainder section

    }

    pthread_exit(0);
}



int main (){

    ifstream input_file("inp-params.txt");   //File for taking the inputs from .

    //scanning the values of n , k, lambda_one , lamda_two from the file .

    input_file >> n;
    input_file >> k;
    input_file >> lambda_one;
    input_file >> lambda_two;

    output_file.open("CAS-Log.txt");  //file for printing the data to .

    cout << "The threads are being accessing the CS now once the program finishes it's execution you may check the CAS-ME.txt file for the output\n";

    output_file<<"CAS-ME Output:\n";

    pthread_t tid[n];  //thread id's of the threads

    //thread creation

    for (int i=0;i<n;i++){
        pthread_create(&tid[i],NULL,testCS,(void *) (long) (i+1));
    }

    //threads joining the main thread

    for (int i=0;i<n;i++){
        pthread_join(tid[i],NULL);
    }

    float average_waiting_time = (float)(waiting_time)/(float)(n*k);  //caluclation of average waiting time of a thread.

    float worst_waiting_time = max_waiting_time;  //worst waiting time

    cout <<"The average time taken by a process to enter CS :"<<average_waiting_time<<" sec\n";

    cout << "The worst time taken by a process to enter the CS in a simulation :"<<worst_waiting_time<<" sec\n";

    cout <<"Check the CAS-Log.txt file for the output\n";

    //closing the files


    input_file.close();

    output_file.close();

    return 0;


 



}
