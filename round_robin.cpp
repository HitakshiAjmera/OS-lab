#include<iostream>
using namespace std;
  
void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum)
{
    //copy of burst times bt[] to store remaining burst times.
    int Cbt[n];
    for (int i = 0 ; i < n ; i++)
        Cbt[i] =  bt[i];
  
    int t = 0; // Current time
  
    // Keep traversing processes in round robin manner until all of them are not done.
    while (1)
    {
        bool done = true;
  
        // Traverse all processes one by one repeatedly
        for (int i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0 then only need to process further
            if (Cbt[i] > 0)
            {
                done = false; // There is a pending process
  
                if (Cbt[i] > quantum)
                {
                    // Increase the value of t i.e. shows how much time a process has been processed
                    t += quantum;
  
                    // Decrease the burst_time of current process by quantum
                    Cbt[i] -= quantum;
                }
  
                // If burst time is smaller than or equal to quantum. Last cycle for this process
                else
                {
                    // Increase the value of t i.e. shows how much time a process has been processed
                    t = t + Cbt[i];
  
                    // Waiting time is current time minus time used by this process
                    wt[i] = t - bt[i];
  
                    // As the process gets fully executed make its remaining burst time = 0
                    Cbt[i] = 0;
                }
            }
        }
  
        // If all processes are done
        if (done == true)
          break;
    }
}
  

void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
  

void findavgTime(int processes[], int n, int bt[],int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
  
    // call Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, quantum);
  
    // call Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
  
    // Display processes along with all details
    cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n";
  
    // Calculate total waiting time and total turn around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
    }
  
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}
  
int main()
{
    int processes[] = { 1, 2, 3,4,5};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {11, 6, 9,7,5};
    int quantum = 2;
    findavgTime(processes, n, burst_time, quantum);
    return 0;
}
