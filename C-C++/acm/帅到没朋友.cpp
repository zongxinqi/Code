#include<iostream>
#include<vector>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{ int N,K,M,m,k,f;  vector<set<int>> ivec; vector<int> s,b; set<int> se;
    cin>>N;
    for(int i=0;i<N;i++)
    {   
		cin>>K;
        se.clear();
        for(int j=0;j<K;j++)
        {   
			cin>>m;
            se.insert(m);
        }
        ivec.push_back(se);
    }

    cin>>M;
    for(int i=0;i<M;i++)
    { 
		cin>>k;
      vector<int>::iterator it;
      it=find(s.begin(),s.end(),k);
      if(it==s.end())
      s.push_back(k);
    }

   for(auto iter=s.begin();iter!=s.end();iter++)
   {f=0;
    for(int i=0;i<N;i++)
      {  if(ivec[i].count(*iter)&&ivec[i].size()>1)
         f=1;
      }
    if(f==0)
    b.push_back(*iter);
   }
    int t=b.size();
   if(t)
    for(int i=0;i<t;i++)
        printf("%05d%c",b[i],i!=t-1?' ':'\n');
   else
    cout<<"No one is handsome";

 return 0;
}
