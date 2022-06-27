#include <iostream>
#include <fstream>
using namespace std;
#define MAX 500

int no_processes = 0;
int pid [MAX];          //array for process identifiers of each process.
int process_time [MAX]; //array for processing time of each process. 
int period_time [MAX];  //array for period time of each process.
int no_times[MAX];      //array for no of repetations of each process.

//This function caluclates the position of the process which is the ready queue & has high priority (earliest deadline )

//in pid array

// i.e. this function gives the position of the process which will to be executed next in pid array.

int min_process_id (int dead_line[],int remaining[]){

    int a=-1;

    int b = MAX ;
    for (int i=0;i<no_processes;i++){
        
        //This is the condition of checking whether a process is in ready queue i.e the process have it's time &

        //it's remaining time should be less than the deadline time otherwise it can't be completed before deadline.

        if (remaining[i]>0 && remaining[i]<=dead_line[i]){
            
            //This if statement gives the position of the process with nearest deadline.

            if (dead_line[i]<b){

               b= dead_line[i];

               a=i;

            }
        }
    }
    return a; //returning the position of the earliest deadline process.

    //Now the next process to be executed has pid in pid[a].

}

//This function implements the Earliest Deadline First scheduling algorithm.

//Here the input is the total time in which the processes are being scheduled.

void EDF(int total_time)
{  
    //creating files EDF-log.txt & EDF-stats.txt

    ofstream EDF_log ( "EDF-log.txt"); 
    ofstream EDF_stats("EDF-stats.txt");
    
    //this prints out the details of the processes that are to be scheduled to EDF-log.txt file.

    for (int i=0;i<no_processes;i++){
        EDF_log<<"Process P"<<i+1<<":processing time="<<process_time[i]<<";deadline:"<<period_time[i]<<";period:"
        <<period_time[i]<<" joined the system at time 0\n";
    }

    int remaining_time[no_processes]; //array for storing the remaining times of the processes.
    int no_iterations[no_processes];  //array for storing the no of times that a process is executed.
    int deadline_time[no_processes];  //array for storing deadlines of the processes.
    int waiting_time[no_processes];   //array for storing waiting times of the processes.
    int missed[no_processes];         //array for storing the no of times that a process is being missed.
    int before=-1;                    //just a intialization for my convience.
    int count[no_processes];

    //Intializing the array values .

    for(int i=0;i<no_processes;i++)
    {
        remaining_time[i]=process_time[i]; //before execution of process it's remaining time is it's processing time.
        no_iterations[i]=0;                
        deadline_time[i]=period_time[i];
        waiting_time[i]=0;
        missed[i]=0;
        count[i]=0;
    }

    
    //Here we caluclate the process that is to be executed next for each second.

    for(int i=0; i<total_time;i++)
    {   
        for(int j=0;j<no_processes;j++)
        {
            //This is the condition for finding the processes which missed their deadlines.

            // i%period_time[j]==0 indicates that it is point where the the 1st for loop is at the deadline of the process.

            if(i%period_time[j]==0 && no_iterations[j]<=no_times[j])
            {
                //After the dealine if a process still had its remaining time then it had missed the deadline.

                if(remaining_time[j]>0 && no_iterations[j]>0)
                {
                    missed[j]=missed[j]+1; //increasing the count for no of times a process is missed.

                    count[j]=1;

                    EDF_log<<"The process P"<<pid[j]<<" had missed the deadline at "<<i<<"\n";

                    // if we found that any process will miss deadline at the start of execution of the process 

                    //then it will be terminated immediately as it will miss it's deadline later .
                }

                //In an iteration if a process had missed it's deadline it wont affect the other iterations.

                remaining_time[j]=process_time[j]; //intializing the remianing time again as process time for next iterations.

                no_iterations[j]+=1;               //increasing no of iterations.

                deadline_time[j]=period_time[j];   //intializing deadline again as period for next iterations.
            }

            //If the no of iterations had execuded it's value then it will be out of the system.

            if(no_iterations[j]>no_times[j])
            {
                remaining_time[j]=0; //we through this process out of system as it has completed it's iterations.
            }
        }
        
        //This is the next process that will be executed .

        int after  = min_process_id(deadline_time,remaining_time);

        //So, the remaining time for that process will be decreased by 1 as it will be occupied for next 1 second.

        remaining_time[after]-=1;

        for(int j=0;j<no_processes;j++)
        {
            //the deadline of the process which is being executed will be decreased by 1 & .

            //The deadline will be again the period after each ietarion (mentioned in line 112).

            deadline_time[j]-=1;

            //the waiting time for all processes other than 'after' will be increased by 1 
            
            //as there are not being executed for the next 1 sec.

            if(j!=after && remaining_time[j]!=0)
            {
                waiting_time[j]+=1;
            }
        }

        //This araises the following cases means there will be change of process or etc at this second.

        if(before!=after)
        {
            //If the before process  has completed it's time .

             if(remaining_time[before]==0 && pid[before]!=0)
            {
                EDF_log<<"Process P"<<pid[before]<<" finishes execution at time "<<i<<"\n";
            }

            //If the before process has remaining time then it will be preempted by another due to priority.

            if(pid[before]!=0 && pid[after]!=0 && remaining_time[before]!=0)
            {
                
               EDF_log<<"Process P"<<pid[before]<<" is preemepted by Process P"<<pid[after]<<" at time "<<i<<
                ".Remaining processing time  "<<remaining_time[before]<<"\n";
                

            }

            //This indiactes that a process is being started or resuming its execution..

            if(after!=-1)
            {
                if (remaining_time[after]==process_time[after]-1){

                    EDF_log<<"Process P"<<pid[after]<<" Starts execution at time "<<i<<"\n";

                }
                else {

                   EDF_log<<"Process P"<<pid[after]<<" resumes execution at time "<<i<<"\n";
                   
                }
            }
            
            //This indicates all the processes completed before their deadlines. or In ready queue we have only those 

            //processes which can't be completed before their deadlines so that processes will be terminated 

            //& CPU will be idle doing no work.

            if(after==-1)
            {
                EDF_log<<"CPU is idle from "<<i<<"\n";
            
            }
            
            
            before=after;
        }
        
    }

    int total_times=0 ;       //variable for caluclating total no of processes.

    int total_missed=0;       //variable for caluclating no of processes that missed their deadlines.

    int total_waiting_time=0; //variable for caluclating the total waiting time of all processes.

    float average_waiting_time[no_processes]; //array for storing waiting times of each process.

    for (int i=0;i<no_processes;i++){

        //caluclation of total no of processes.

        total_times=total_times+no_times[i]; 
    
        //caluclation of no of processes that missed their deadlines.

        total_missed=total_missed+missed[i];
    
        //caluclation of total waiting time of all processes.

        total_waiting_time=total_waiting_time+waiting_time[i];

        //caluclation of waiting times of each process.

        average_waiting_time[i]=(float)waiting_time[i]/(float)no_times[i];
    }

    float total_average_waiting_time = (float)total_waiting_time/(float)total_times; 

    EDF_stats<<"No of processes that came into system: "<<total_times<<"\n";

    EDF_stats<<"No of processes that are successfully completed: "<<total_times-total_missed<<"\n";

    EDF_stats<<"No of processes that missed their deadlines: "<<total_missed<<"\n";

    for (int i=0;i<no_processes;i++){
        EDF_stats<<"Process P"<<pid[i]<<" had missed the deadline for "<<missed[i]<<" times\n";
    }

    for (int i=0;i<no_processes;i++){

        EDF_stats<<"Average waiting time for Process P"<<pid[i]<<" : "<<average_waiting_time[i]<<" milliseconds\n";
    }

    EDF_stats<<"Total average waiting time: "<< total_average_waiting_time<<" milliseconds\n";

    EDF_log.close();
    EDF_stats.close();
}


int main() {

    ifstream input_file("inp-params.txt");

    //scaning the values from the input file & storing them in global arrays declared before.

    int n;

    input_file>>no_processes;

    for (int i=0;i<no_processes;i++){
    
        input_file>>pid[i];        

        input_file>>process_time[i];
        
        input_file>>period_time[i];
        
        input_file>>no_times[i];
    
    }

    int a = period_time [0] * no_times [0] ;

    for (int i=1;i<no_processes;i++){
        if (a < period_time[i] * no_times[i]){
            a = period_time [i] * no_times[i];
        }
    }

    //This integer a denotes the maximum time in which the processes will be scheduled .

    EDF(a);

    input_file.close();

    cout<<"\nCheck the EDF-log.txt & EDF-stats.txt files for the ouput\n";


    return 0;
}