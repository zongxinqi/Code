/** 
 * ����������� 
 * �Ż����ڴ�ռ��ʹ�� 
 * �۲쵽һ����: ÿһ��Ԫ�صļ���,ֻ����������, ���, �ϱߵ�����Ԫ����� 
 * ���Կ���len(x) + 3 
 * 3������ ����ΪleftAbove, left, above 
 */  
#include<iostream>  
#include<string>  
#include<memory.h>  
using namespace std;  
  
  
int LCS(string x, string y);  
   
int main() {  
    string x, y;  
    cin>>x>>y;  
    LCS(x, y);  
}  
  
int LCS(string x, string y){  
    int lenx = x.length();  
    int leny = y.length();  
      
    int leftabove, left, above; //���Ͻ� �� ��  
  
    int *compute = new int[leny + 1]; //compute[0] ��ԭ����calc[i][0] for i in [0, lenx];  
    memset(compute, 0, (leny + 1) * sizeof(int));  
    for(int i = 1; i <= lenx; i++) {  
        leftabove = left = compute[0];  
        above = compute[1];  
        for(int t = 0; t <= leny; t++) cout<<compute[t]<<" ";  
        cout<<endl;  
        for(int j = 1; j <= leny; j++) {   
            //����,���Ҹ�������������  
            if(x[i - 1] == y[j - 1]) compute[j] = leftabove + 1;  
            else if(left > above)    compute[j] = left;  
            else compute[j] = above;  
  
            //���´���������,���м��ɵ�Ŷ  
            leftabove = above;  
            above = compute[j + 1];  
            left = compute[j];  
        }  
    }  
    cout<<compute[leny]<<endl;   
    delete[] compute;  
}  
