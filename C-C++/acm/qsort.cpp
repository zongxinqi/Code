#include <iostream>
#include <stdio.h>
using namespace std;
int a[1000001];
void quicksort(int a[],int s,int t)
{
    int i=s,j=t;
    int tmp = a[s];
    if(s<t){    //������Ԫ��ʣ0������1����ʱ��ֹͣ
        while(i<j){
            while(i<j && a[j]>=tmp)
                j--;
            a[i] = a[j];
            while(i<j && a[i]<=tmp)
                i++;
            a[j] = a[i];
        } 
        a[i] = tmp;
        quicksort(a,s,i-1);    //��������ݹ����� 
        quicksort(a,i+1,t);    //��������ݹ����� 
    }
}
int main()
{
    int i;
    int n,m;
    while(cin>>n>>m){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        quicksort(a,1,n);
        for(i=n;i>=n-m+1;i--){
            printf("%d",a[i]);
            if(i!=n-m+1)
                printf(" ");
            else 
                printf("\n");
        }
    }
    return 0;
}
