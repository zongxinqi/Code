#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char l1[10];
    int n;
    while(cin>>n){
        if(n==0) break;
        cin>>l1;
        int tree[1025];
        memset(tree,-1,sizeof(tree));
        for(int i=0;l1[i];i++){    //构造二叉搜索树 
            int num = l1[i] - '0';
            int j = 1;
            while(tree[j]!=-1){
                if(num <= tree[j])
                    j = j*2;
                else 
                    j = j*2 + 1;
            }
            tree[j] = num;
        }
        while(n--){    //输入n个序列 
            char l2[10];
            cin>>l2;
            int tree2[1025];
            memset(tree2,-1,sizeof(tree2));
            for(int i=0;l2[i];i++){    //构造比较二叉搜索树 
                int num = l2[i] - '0';
                int j = 1;
                while(tree2[j]!=-1){
                    if(num <= tree2[j])
                        j = j*2;
                    else 
                        j = j*2 + 1;
                }
                tree2[j] = num;
            }
            int i;
            for(i=0;i<=1024&&tree[i]==tree2[i];i++);    //比较 
            if(i>1024)
                cout<<"YES"<<endl;
            else 
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
