#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
#include <queue>  
#include <iostream>  
  
using namespace std;  
  
typedef long long ll;  
const int N = 1005;  
const int INF = 0x3f3f3f3f;  
  
int num[N];  
  
void HeapAdjust(int mother, int len)  
{  
    int tmp = num[mother];  
    for(int i = 2*mother; i <= len; i*=2)  
    {  
        if(i<len && num[i]<num[i+1]) i++;  
        if(num[i]<=tmp) break;//若儿子没有母亲大，则调整完毕  
        num[mother] = num[i];  
        mother = i;  
    }  
    num[mother] = tmp;  
}  
  
void HeapSort(int len)  
{  
    for(int i = len/2; i > 0; i--)  
    {  
        HeapAdjust(i, len);  
    }  
    for(int i = len; i > 1; i--)  
    {  
        swap(num[1], num[i]);  
        HeapAdjust(1, i-1);  
    }  
}  
  
int main()  
{  
   // freopen("in.txt", "r", stdin);  
    int n;  
    char s[N];  
    while(~scanf("%s", s))  
    {  
        int len = strlen(s);  
        int dight = 0;  
        n = 0;  
        int flag = 0;//1标志数字的开始，0表示结束  
        for(int i = 0; i < len; i++)  
        {  
            if(!flag && (s[i]=='5')) continue;  
            else if(s[i] == '5')//把这个数字存起来  
            {  
                num[++n] = dight;  
                dight = 0;  
                flag = 0;  
            }  
            else  
            {  
                dight = dight*10+(s[i]-'0');  
                flag = 1;  
            }  
        }  
        if(dight!=0) num[++n] = dight;  
        HeapSort(n);  
        for(int i = 1; i < n; i++)  
            printf("%d ", num[i]);  
        printf("%d\n", num[n]);  
    }  
    return 0;  
}
