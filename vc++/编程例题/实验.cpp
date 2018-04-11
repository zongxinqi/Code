#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  int h;
  cin>>h;
  float w = (h - 100)*1.8;
  cout<<setiosflags(ios::fixed)<<setprecision(1)<<w;
  return 0;
}
