// SJF Non-Preemtive at 0 arival time
#include<iostream>
using namespace std ; 


int main()
{
    int n,total=0;
    float avg_wt,avg_tat;
    cout<<"Enter the number of process:";
    cin>>n;
    int BT[n],P[n],WT[n],TAT[n];
    cout<<"\nEnter the Burst Time of process: "<<endl;
    for(int i=0;i<n;i++)
    {
    	cout<<"Process "<<i+1<<" : ";
        cin>>BT[i];
        P[i]=i+1;         
    }
//sorting of process according to Burst time
    for(int i=0;i<n;i++)
    {
        int pos=i,temp;
        for(int j=i+1;j<n;j++)
        {
            if(BT[j]<BT[pos])
                pos=j;
        }
        temp=BT[i];
        BT[i]=BT[pos];
        BT[pos]=temp;
        temp=P[i];
        P[i]=P[pos];
        P[pos]=temp;
    }
//Finding waiting time of process
    WT[0]=0;            
    for(int i=1;i<n;i++)
    {
        WT[i]=0;
        for(int j=0;j<i;j++)
            WT[i]+=BT[j];
        total+=WT[i];
    }
    avg_wt=(float)total/n;      
    total=0;
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    for(int i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];  //formula for TAT 
        total+=TAT[i];
        cout<<"\nP"<<P[i]<<"\t\t  "<<BT[i]<<"\t\t    "<<WT[i]<<"\t\t\t"<<TAT[i];
    }
    avg_tat=(float)total/n;    
    cout<<"\n\nAverage Waiting Time= "<<avg_wt;
    cout<<"\nAverage Turnaround Time= "<<avg_tat;
}

/**
OUTPUT:-
Enter the number of process:5

Enter the Burst Time of process:
Process 1 : 12
Process 2 : 8
Process 3 : 14
Process 4 : 6
Process 5 : 11

Process         Burst Time      Waiting Time    Turnaround Time
P4                6                 0                   6
P2                8                 6                   14
P5                11                14                  25
P1                12                25                  37
P3                14                37                  51

Average Waiting Time= 16.4
Average Turnaround Time= 26.6
--------------------------------
**/
