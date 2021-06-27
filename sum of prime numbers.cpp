#include<iostream>
using namespace std;
int num,i,arr[20],sum,j,k,a;
		
    void primeno(int num)
    {
	    for(i=1;i<num;i++)
	    {
		    if((i%2!=0)||(i%2==1))
		    {
			    cout<<"the numbers which are prime are:"<<i<<endl;	
			    arr[a]=i;
			    a++;
		    }
	    }
	    cout<<a<<endl;
	   for(j=1;j<=a;j++)
	   {
	    for(k=1;k<=a;k++)
	     {
		    sum=arr[j]+arr[k];
		    if(sum==num)
		    {
		      cout<<"sum of num"<<num<<"is"<<arr[j]<<"+"<<arr[k]<<endl;
		    }
	     }
       }		
    }
int main()
{
	cout<<"Enter the number:";
	cin>>num;
	primeno(num);
}
