//Priority scheduling
#include<iostream>
using namespace std;

int main()
{
    int n,total=0,pos,temp;
	float avg_wt,avg_tat;
    cout<<"Enter Total Number of Process: ";
    cin>>n;
    int bt[n],p[n],wt[n],tat[n],pr[n];
 
    cout<<"\nEnter Burst Time and Priority"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"\nP"<<i+1<<endl;
        cout<<"Burst Time:";
        cin>>bt[i];
        cout<<"Priority: ";
        cin>>pr[i];
        p[i]=i+1;           
    }
 
    for(int i=0;i<n;i++)
    {
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	
    for(int i=1;i<n;i++)
    {
        wt[i]=0;
        for(int j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      
    total=0;
 
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        cout<<"\nP"<<p[i]<<"\t\t"<<bt[i]<<"  \t\t"<<wt[i]<<"    \t\t\t"<<tat[i];
    }
 
    avg_tat=total/n;     
    cout<<"\n\nAverage Waiting Time = "<<avg_wt;
    cout<<"\nAverage Turnaround Time= "<<avg_tat;
 
	return 0;
}
/**
OUTPUT:-
Enter Total Number of Process: 4

Enter Burst Time and Priority

P1
Burst Time:8
Priority: 2

P2
Burst Time:9
Priority: 1

P3
Burst Time:10
Priority: 1

P4
Burst Time:12
Priority: 3

Process     Burst Time          Waiting Time    Turnaround Time
P2              9               0                       9
P3              10              9                       19
P1              8               19                      27
P4              12              27                      39

Average Waiting Time = 13
Average Turnaround Time= 23
**/
