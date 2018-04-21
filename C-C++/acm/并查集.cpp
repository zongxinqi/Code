#include <iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
  
using namespace std;  
  
int pre[1100];  
  
int findset(int v)  
{  
    int t1,t2=v;  
    while(v!=pre[v])    v=pre[v];  
    while(t2!=v)  
    {  
        t1=pre[t2];  
        pre[t2]=v;  
        t2=t1;  
    }  
    return v;  
}  
  
void unions(int u,int v)  
{  
    int t1=findset(u);  
    int t2=findset(v);  
    if(t1!=t2)  pre[t1]=t2;  
}  
  
int main()  
{  
    int n,m;  
    while(~scanf("%d",&n)&&n)  
    {  
        cin>>m;  
        for(int i=1;i<=n;i++)   pre[i]=i;  
        for(int i=0;i<m;i++)  
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            unions(u,v);  
        }  
        int ans=-1;  
        for(int i=1;i<=n;i++)  
            if(pre[i]==i)   ans++;  
        cout<<ans<<endl;  
    }  
}
