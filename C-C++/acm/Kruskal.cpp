#include<iostream>
#include<algorithm>
#define N 110
using namespace std;

struct node{int u,v,w;}edge[N*N];
int parent[N];

bool cmp(node a,node b)
{
    if(a.w<=b.w) return true;
    return false;
}

int find(int a)
{
    if(a!=parent[a])
        return find(parent[a]);
    else return a;
}

int kruskal(int n,int m)
{
    sort(edge,edge+m,cmp);
    int i,x,y,ans=0;
    for(i=0;i<m;i++)
    {
        x=edge[i].u;
        y=edge[i].v;
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            ans+=edge[i].w;
            parent[y]=x;
        }
    }
    return ans;
}

int main()
{
    int n,q,k,i,j,m;
    while(cin>>n)
    {
        m=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {    
                cin>>k;
                if(i>=j) continue;
                edge[m].u=i;
                edge[m].v=j;
                edge[m].w=k;
                m++;
            }
        }
        for(k=1;k<=n;k++) parent[k]=k;
        cin>>q;
        for(k=1;k<=q;k++)
        {
            cin>>i>>j;
            i=find(i);//WA几次原来是这里的原因，要注意！！
            j=find(j);
            parent[j]=i;
        }
        cout<<kruskal(n,m)<<endl;
    }
    return 0;
}
