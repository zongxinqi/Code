#include<iostream>
#include<string.h> 
#include<stack>
using namespace std;
int main()
{
	string num[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int n;
	stack<string>stk;
	cin>>n;
	if(n < 0) {printf("fu ");n = -n;}
	int ans;
	if(n == 0) printf("ling");
	while(n)
	{
		ans = n%10;
		stk.push(num[ans]);
		n/=10;
	}
	while(!stk.empty())
	{
		if(stk.size() != 1)
		cout<<stk.top()<<" ";
		else cout<<stk.top();
		stk.pop();
	}
	return 0;
}
