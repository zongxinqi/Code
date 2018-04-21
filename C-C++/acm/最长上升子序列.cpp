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
        if(b[i])//�����ǰ���Ѿ�ѡȡ���ˣ�������  
            continue;  
        *lower_bound(dp,dp+n,a[i])=a[i];  
        int d=lower_bound(dp,dp+n,a[i])-dp;  
        if(d>k)//ʹ�ö��ֲ��Ҳ����λ��Ӧ���������k�ſ��Խ��б�ǣ������Ƕ����������������d��С��0������kӦ����-1��ʼ������������һ�º����׾��������ˣ�  
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
