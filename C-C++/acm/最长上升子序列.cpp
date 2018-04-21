#include<iostream>  
#include<cstdlib>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<map>  
#define INF 0x3f3f3f3f  
#define N 1000  
using namespace std;  
int b[N],a[N],dp[N],n;  
int maxlen()  
{  
    int i,res,k=-1;  
    for(i=0; i<n; i++)  
    {  
        if(b[i])//如果当前数已经选取过了，跳过；  
            continue;  
        *lower_bound(dp,dp+n,a[i])=a[i];  
        int d=lower_bound(dp,dp+n,a[i])-dp;  
        if(d>k)//使用二分查找插入的位置应该满足大于k才可以进行标记，避免标记多余的数；另外由于d最小是0，所以k应当从-1开始；（单步调试一下很容易就能明白了）  
        {  
            b[i]=1;  
            k++;  
        }  
    }  
    res=lower_bound(dp,dp+n,INF)-dp;  
    return res;  
}  
int main()  
{  
    int i,answer,ans;  
    while(~scanf("%d",&n))  
    {  
        memset(b,0,sizeof(b));  
        memset(a,0,sizeof(a));  
        for(i=0; i<n; i++)  
            scanf("%d",&a[i]);  
        int num=1;  
        fill(dp,dp+n,INF);  
        ans=maxlen();  
        while(1)  
        {  
            fill(dp,dp+n,INF);  
            answer=maxlen();  
            if(answer!=ans)  
                break;  
            else  
                num++;  
        }  
        printf("%d\n%d\n",ans,num);  
    }  
    return 0;  
}
