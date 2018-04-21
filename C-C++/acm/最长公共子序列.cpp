#include <iostream> 
#include<cstring> 
using namespace std;  
#define M 5005  
  
int dp[M][M];  
char a[M], b[M];  
  
int main()  
{  
    int i, j, la, lb;  
    while (~scanf ("%s%s", a, b))  
    {  
        la = strlen (a), lb = strlen (b);  
        for (i = 0; i < la; i++) //边界初始化  
            dp[i][0] = 0;  
        for (j = 0; j < lb; j++)  
            dp[0][j] = 0;  
        for (i = 1; i <= la; i++)  
        {  
            for (j = 1; j <= lb; j++)  
            {  
                //状态转移  
                if (a[i-1] == b[j-1])  
                    dp[i][j] = dp[i-1][j-1] + 1;  
                else dp[i][j] = max (dp[i-1][j], dp[i][j-1]);  
            }  
        }  
        printf ("%d\n", dp[la][lb]);  
    }  
    return 0;  
}  
