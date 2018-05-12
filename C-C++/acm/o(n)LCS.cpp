/** 
 * 最长公共子序列 
 * 优化了内存空间的使用 
 * 观察到一件事: 每一个元素的计算,只和其在左上, 左边, 上边的三个元素相关 
 * 可以考虑len(x) + 3 
 * 3个变量 定义为leftAbove, left, above 
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
      
    int leftabove, left, above; //左上角 左 上  
  
    int *compute = new int[leny + 1]; //compute[0] 即原来的calc[i][0] for i in [0, lenx];  
    memset(compute, 0, (leny + 1) * sizeof(int));  
    for(int i = 1; i <= lenx; i++) {  
        leftabove = left = compute[0];  
        above = compute[1];  
        for(int t = 0; t <= leny; t++) cout<<compute[t]<<" ";  
        cout<<endl;  
        for(int j = 1; j <= leny; j++) {   
            //计算,并且更新这三个变量  
            if(x[i - 1] == y[j - 1]) compute[j] = leftabove + 1;  
            else if(left > above)    compute[j] = left;  
            else compute[j] = above;  
  
            //更新此三个变量,很有技巧的哦  
            leftabove = above;  
            above = compute[j + 1];  
            left = compute[j];  
        }  
    }  
    cout<<compute[leny]<<endl;   
    delete[] compute;  
}  
