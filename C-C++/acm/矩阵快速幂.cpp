#include<bits/stdc++.h>
using namespace std;
typedef long long ll;  
const int INF=0x3f3f3f3f;  
const ll mod = 1e9 + 7;  
struct matrix  
{  
    ll a[4][4];  
    matrix(){  
    memset(a,0,sizeof(a));  
    }  
};  
matrix multi(matrix b,matrix a)  
{  
    matrix c;  
    for(int i=1;i<=3;i++){  
        for(int j=1;j<=3;j++){  
            if(a.a[i][j]==0) continue;  
          for(int k=1;k<=3;k++){  
            c.a[i][k] = (c.a[i][k] + a.a[i][j] * b.a[j][k]) % mod;  
          }  
        }  
    }  
    return c;  
}  
matrix pow_matrix(matrix a,ll n)  
{  
    matrix b;  
    b.a[1][3] = b.a[2][1] = b.a[2][2]= b.a[3][2] = 1;  
    while(n){  
        if(n&1) a = multi(b,a);  
        b = multi(b,b);  
        n>>=1;  
    }  
    return a;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--){  
        ll n;  
        scanf("%lld",&n);  
        if(n==2) printf("3\n");  
        else{  
            matrix ans;  
            ans.a[1][1] = ans.a[1][2] = ans.a[1][3] = 1;  
            ans = pow_matrix(ans,n-2);  
            printf("%lld\n",(ans.a[1][1]+ans.a[1][2]+ans.a[1][3])%mod);  
        }  
    }  
}   
