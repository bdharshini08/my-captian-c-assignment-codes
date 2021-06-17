#include<iostream>
using namespace std;
int main()
{
	int age,years;
	cout<<"Enter your age of the person:";
	cin>>age;
	if(age>=18)
	{
		cout<<"the person is eligible to vote";
	}
	else
	{
		cout<<"the person is not eligible to vote";
		years=18-age;	
		cout<<"\nyou will be able to vote after:"<<years<<"years";
	}
	return 0;
}
