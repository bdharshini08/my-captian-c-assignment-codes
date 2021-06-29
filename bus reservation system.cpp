#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdio>
#include<cstdlib>
using namespace std;
static int p = 0;
class a
{
	char busno[5],drivername[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		   void install();
		   void allotment();
		   void empty();
		   void show();
		   void avail();
		   void position(int l);
}
bus[10];
void vline(char ch)
{
	for(int i=80;i>0;i--)
	cout<<ch;
}
void a::install()
{
	cout<<"Enter bus no:";
	cin>>bus[p].busno;
	cout<<"Enter the driver's name:";
	cin>>bus[p].drivername;
	cout<<"\nArrival time of the bus:";
	cin>>bus[p].arrival;
	cout<<"\nDeparture time:";
	cin>>bus[p].depart;
	cout<<"\nFrom:\t\t";
	cin>>bus[p].from;
	cout<<"\nTo:\t\t";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void a::allotment()
{
	int seat,n;
	char number[5];
	top:
		cout<<"Bus no:";
		cin>>number;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busno, number)==0)
			break;
		}
		while(n<=p)
		{
			cout<<"\nseat number:";
			cin>>seat;
			if(seat>32)
			{
				cout<<"\nthere are only 32 seats avaliable in the bus";
			}
			else
			{
			 if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
			 {
			 	cout<<"Enter passanger's name:";
			 	cin>>bus[n].seat[seat/4][(seat%4)-1];
			 	break;
			 }
			 else
			     cout<<"the seat no.is already reserved.\n";
			}
		}
		if(n>p)
		{
			cout<<"\nEnter the correct bus no.\n";
			goto top;
		}
}
void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}
void a::show()
{
	int n;
	char number[5];
	cout<<"Enter bus no:";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busno, number)==0)
		break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"bus no:\t"<<bus[n].busno
		<<"\nDriver:\t"<<bus[n].drivername<<"\nArrival time:\t"
		<<bus[n].arrival<<"\tDepartur time:"<<bus[n].depart
		<<"\nFrom:\t\t"<<bus[n].from<<"\t\tTo:\t\t"<<
		bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1,i,j;
		for(i=0;i<8;i++)
		{
			for(j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"empty")!=0)
				cout<<"\nThe seat no"<<(a-1)<<"is reserved for"<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n>p)
	   cout<<"Enter correct bus no:";
}
void a::position(int l)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j],"Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
			}
		}
	}
	cout<<"\n\nThere are"<<p<<"seat empty in bus no:"<<bus[l].busno;
}
void a::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"bus no:\t"<<bus[n].busno
		<<"\nDriver:\t"<<bus[n].drivername<<"\nArrival time:\t"
		<<bus[n].arrival<<"\tDepartur time:"<<bus[n].depart
		<<"\nFrom:\t\t"<<bus[n].from<<"\t\tTo:\t\t"<<
		bus[n].to<<"\n";
		vline('*');
		vline('_');
		
	}
}
int main()
{
	system("cls");
	int choice;
	while(1)
	{
		//system("cls");
		cout<<"\n1.Install\t\n";
		cout<<"2.reservation\t\n";
		cout<<"3.show\t\n";
		cout<<"4.buses available\t\n";
		cout<<"5.Exit\t\n";
		cout<<"enter your choice:\t";
		cin>>choice;
		switch(choice)
		{
			case 1:bus[p].install();
			       break;
			case 2:bus[p].allotment();
			       break;
		    case 3:bus[p].show();
			       break;
			case 4:bus[p].avail();
			       break;
		    case 5:exit(0);
			       break;
		}
	}
}

