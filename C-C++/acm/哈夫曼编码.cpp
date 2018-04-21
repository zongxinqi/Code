#include<bits/stdc++.h> 
using namespace std;
int cal(char x){
	return x - 'a' + 1;
}  
typedef struct Tree  
{  
    int freq;//出现频率,即 权值  
    char key;//字符  
    struct Tree *left, *right;  
    Tree(int fr=0, char k='\0',Tree *l=nullptr, Tree *r=nullptr):  
        freq(fr),key(k),left(l),right(r){};  
}Tree,*pTree;  
  
// 自定义仿函数  
struct cmp  
{  
    bool operator() (Tree *a, Tree *b)  
    {  
        return a->freq>b->freq;//注意是> or < 不能用 - 和c中的qsort不同  
    }  
};  
// 优先队列  
priority_queue<pTree,vector<pTree>,cmp> pque;  
  
// 利用中序遍历的方法输出霍夫曼编码  
//左0右1，迭代完一次st回退一个字符  
void print_Code(Tree *proot, string st)  
{  
    if(proot == NULL)  
        return ;  
  
    if(proot->left)  
    {  
        st +='0';  
    }  
    print_Code(proot->left, st);  
    if(!proot->left && !proot->right)//叶子  
    {  
        printf("%c: ", proot->key);  
        for(size_t i=0; i<st.length(); ++i)  
            printf("%c", st[i]);  
        printf("\n");  
    }  
    st.pop_back();//回退一个字符  
    if(proot->right)  
        st+='1';  
    print_Code(proot->right, st);  
}  
  
//清空堆上分配的内存空间  
void del(Tree *proot)  
{  
    if(proot == nullptr)  
        return ;  
    del(proot->left);  
    del(proot->right);  
    delete proot;  
}  
// 霍夫曼编码  
void huffman()  
{    
    string c;cin>>c;
    int a[30] = {0};
    for(int i = 0;i < c.length();i++) a[cal(c[i])]++; 
    // 读入测试数据  
    for(int i = 0; i < 26;i++)  
    {  
        Tree *pt= new Tree;  
        if(a[i]){
        	pt->key = i - 1 + 'a';  
        	pt->freq = a[i];  
        	pque.push(pt);
		}    
    }  
    //将森林中最小的两个频度组成树，放回森林。直到森林中只有一棵树。  
    while(pque.size()>1)  
    {  
        Tree *proot = new Tree;  
        pTree pl,pr;  
        pl = pque.top();  
        pque.pop();  
        pr = pque.top();  
        pque.pop();  
  
        proot->freq = pl->freq + pr->freq;  
        proot->left = pl;  
        proot->right = pr;  
        pque.push(proot);  
    }  
    string s;  
    print_Code(pque.top(), s);  
    del(pque.top());  
}  
int main()  
{    
    huffman();  
    return 0;  
} 
