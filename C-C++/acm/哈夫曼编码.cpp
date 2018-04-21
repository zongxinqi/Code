#include<bits/stdc++.h> 
using namespace std;
int cal(char x){
	return x - 'a' + 1;
}  
typedef struct Tree  
{  
    int freq;//����Ƶ��,�� Ȩֵ  
    char key;//�ַ�  
    struct Tree *left, *right;  
    Tree(int fr=0, char k='\0',Tree *l=nullptr, Tree *r=nullptr):  
        freq(fr),key(k),left(l),right(r){};  
}Tree,*pTree;  
  
// �Զ���º���  
struct cmp  
{  
    bool operator() (Tree *a, Tree *b)  
    {  
        return a->freq>b->freq;//ע����> or < ������ - ��c�е�qsort��ͬ  
    }  
};  
// ���ȶ���  
priority_queue<pTree,vector<pTree>,cmp> pque;  
  
// ������������ķ����������������  
//��0��1��������һ��st����һ���ַ�  
void print_Code(Tree *proot, string st)  
{  
    if(proot == NULL)  
        return ;  
  
    if(proot->left)  
    {  
        st +='0';  
    }  
    print_Code(proot->left, st);  
    if(!proot->left && !proot->right)//Ҷ��  
    {  
        printf("%c: ", proot->key);  
        for(size_t i=0; i<st.length(); ++i)  
            printf("%c", st[i]);  
        printf("\n");  
    }  
    st.pop_back();//����һ���ַ�  
    if(proot->right)  
        st+='1';  
    print_Code(proot->right, st);  
}  
  
//��ն��Ϸ�����ڴ�ռ�  
void del(Tree *proot)  
{  
    if(proot == nullptr)  
        return ;  
    del(proot->left);  
    del(proot->right);  
    delete proot;  
}  
// ����������  
void huffman()  
{    
    string c;cin>>c;
    int a[30] = {0};
    for(int i = 0;i < c.length();i++) a[cal(c[i])]++; 
    // �����������  
    for(int i = 0; i < 26;i++)  
    {  
        Tree *pt= new Tree;  
        if(a[i]){
        	pt->key = i - 1 + 'a';  
        	pt->freq = a[i];  
        	pque.push(pt);
		}    
    }  
    //��ɭ������С������Ƶ����������Ż�ɭ�֡�ֱ��ɭ����ֻ��һ������  
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
