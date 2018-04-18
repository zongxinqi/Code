#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  char c;
  int n;
  cin>>n;
  while(n--)
  {
   	float h; 
    cin>>c>>h;
    if(c == 'M') cout<<setiosflags(ios::fixed)<<setprecision(2)<<h/1.09<<endl;
    else cout<<setiosflags(ios::fixed)<<setprecision(2)<<h*1.09<<endl;
  }
  return 0;
}
 
