#include<iostream>
using namespace std;
void main()
{
	int n;
	cin>>n;
	int *a =new int[n];
	int *order=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		order[i]=0;
	}
	int eqNum=0;
	for(int ord=1;ord+eqNum<=n;ord++)
	{
		int first =0;
		while(order[first]!=0)first++;
		//cout<<"ord:"<<ord<<",first:"<<first;
		int min=a[first],minAt=first;
		for(int j=first+1;j<n;j++)
		{
			if(order[j]!=0)continue;
			if(a[j]<min){min=a[j];minAt=j;}
			}
			//cout<<",minAt:"<<minAt<<",min:"<<min<<endl;
			int ord0=ord;
			order[minAt]=ord0;
			for(int k=minAt+1;k<n;k++){
				if(a[k]==min){order[k]=ord0;eqNum++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i>0)cout<<"";
		cout<<order[i];
	}
}
