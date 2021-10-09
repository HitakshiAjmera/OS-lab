#include<iostream>
using namespace std;
 
int m=1,full=0,empty=5,x=0;
 
int wait(int s)
{
	return (--s);
}
 
int signal(int s)
{
	return(++s);
}
 
void producer()
{
	m=wait(m);
	full=signal(full);
	empty=wait(empty);
	x++;
	cout<<"\nProducer produces the item "<<x;
	m=signal(m);
}
 
void consumer()
{
	m=wait(m);
	full=wait(full);
	empty=signal(empty);
	cout<<"\nConsumer consumes item "<<x;
	x--;
	m=signal(m);
} 
int main()
{
	int n;
	cout<<"\n1.Producer\n2.Consumer\n3.Exit";
	while(1)
	{
		cout<<"\nEnter your choice:";
		cin>>n;
		switch(n)
		{
			case 1:	if((m==1)&&(empty!=0))
						producer();
					else
						cout<<"Buffer is full!!";
					break;
			case 2:	if((m==1)&&(full!=0))
						consumer();
					else
						cout<<"Buffer is empty!!";
					break;
			case 3:
					exit(0);
					break;
		}
	}
	
	return 0;
}
/**
OUTPUT:-
1.Producer
2.Consumer
3.Exit
Enter your choice:2
Buffer is empty!!
Enter your choice:1

Producer produces the item 1
Enter your choice:1

Producer produces the item 2
Enter your choice:1

Producer produces the item 3
Enter your choice:1

Producer produces the item 4
Enter your choice:1

Producer produces the item 5
Enter your choice:1
Buffer is full!!
Enter your choice:2

Consumer consumes item 5
Enter your choice:2

Consumer consumes item 4
Enter your choice:3

**/

