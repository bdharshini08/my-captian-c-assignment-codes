#include<iostream>
using namespace std;
int main()
{
	int *p;
	int arr[10],i,n;
	cout<<"enter the number of elements:";
	cin>>n;
	cout<<"enter the  elements:";
	for(i=0;i<n;i++)
	cin>>arr[i];
	p=arr;
	for(i=0;i<n;i++)
	{
		cout<<"the array elements are:"<<*p<<endl;
		p++;
	}
}
