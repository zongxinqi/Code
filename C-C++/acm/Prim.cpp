#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=110;
const int INF=0x3f3f3f3f;

int n,ans;
int map[N][N],dis[N],vis[N];

void Prim(){
    int i;
    for(i=1;i<=n;i++){
        dis[i]=map[1][i];
        vis[i]=0;
    }
    dis[1]=0;
    vis[1]=1;
    int j,k,tmp;
    for(i=1;i<=n;i++){
        tmp=INF;
        for(j=1;j<=n;j++)
            if(!vis[j] && tmp>dis[j]){
                k=j;
                tmp=dis[j];
            }
        if(tmp==INF)
            break;
        vis[k]=1;
        ans+=dis[k];
        for(j=1;j<=n;j++)
            if(!vis[j] && dis[j]>map[k][j])
                dis[j]=map[k][j];
    }
}

int main(){

    //freopen("input.txt","r",stdin);

    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&map[i][j]);
        int q,a,b;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&a,&b);
            map[a][b]=map[b][a]=0;
        }
        ans=0;
        Prim();
        printf("%d\n",ans);
    }
    return 0;
}
