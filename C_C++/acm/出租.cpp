#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int arr[10] = {0};
	int index[11] = {0};
	int flag = 0;
	int i;
	for(i = 0;i < s.length();i++)
	{
		arr[s[i] - '0'] = s[i] - '0'; 
		if(s[i] == '0') flag = 1;
	}
	sort(arr,arr+10,greater<int>());
	int minn = 10;
	for(i = 0;arr[i] != 0;i++)
	{
		if(minn > arr[i]) minn = arr[i];
	}
	cout<<"int[] arr = new int[]{";
	for(i = 0;arr[i] != 0;i++)
	{
		cout<<arr[i];
		if(arr[i] != minn) cout<<",";
	}
	if(flag&&arr[0] != 0) cout<<",0";
	else if(flag&&arr[0] == 0) cout<<"0";
	cout<<"};"<<endl;
	for(i = 0;i < s.length();i++)
	{
		for(int j = 0;j < 10;j++)
		{
			if(s[i] - '0' == arr[j])
			{
				index[i] = j;
				break;
			}
		}
	}
	cout<<"int[] index = new int[]{";
	for(i = 0;i < 11;i++)
	{
		cout<<index[i];
		if(i != 10) cout<<",";
	}
	cout<<"};";
	return 0;
}
