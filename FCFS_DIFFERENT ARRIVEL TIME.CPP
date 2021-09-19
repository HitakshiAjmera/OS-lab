#include <iostream>
using namespace std;
int main()
{
int n,avg_tat=0,avg_wt=0;
cout<<"Enter no. of proccess: ";
cin>>n;
int pro[n],At[n],Bt[n],wt[n],Tat[n];
wt[0]=0;
for(int i =0;i<n;i++)
{
pro[i]=i;
cout<<"Enter arival and brust time of process "<<i+1<<endl;
cout<<"AT :- "; cin>> At[i];
cout<<"BT :- ";cin>>Bt[i];
}
//calculating waiting time
for(int i =1;i<n;i++)
{
wt[i]=Bt[i-1]+wt[i-1];
}
//calculating turn arround time
for(int i =0;i<n;i++)
{
Tat[i]=Bt[i]+wt[i];
}

cout<<"\nTat\t\tWt"<<endl;
for(int i =0;i<n;i++)
{cout<<Tat[i]<<"\t\t"<<wt[i]<<endl;
avg_tat=Tat[i]+avg_tat;
avg_wt=wt[i]+avg_wt;
}
avg_tat=avg_tat/n;
avg_wt=avg_wt/n;
cout<<"Avg_tat : "<<avg_tat<<endl;
cout<<"Avg_wt : "<<avg_wt<<endl;
return 0;
}
