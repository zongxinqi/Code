#include<bits/stdc++.h>
using namespace std;
typedef struct Tree{
	int freq;
	char key;
	struct Tree *left,*right;
	Tree(int f = 0,char k = '\0',Tree *l = nullptr,Tree *r = nullptr):
		freq(f),key(k),left(l),right(r){};
}Tree,*pTree;
struct cmp{
	bool operator()(Tree *a,Tree *b){
		return a->freq > b->freq;
	}
};
void print_code(Tree *proot,string ans){
	if(proot == nullptr) return ;
	if(proot->left)  ans += '0';
	print_code(proot->left,ans);
	if(!proot->left&&!proot->right){
		cout<<proot->key<<": "<<ans<<endl;
	}
	ans.pop_back();
	if(proot->right) ans += '1';
	print_code(proot->right,ans);
}
void del(Tree *proot){
	if(proot == nullptr) return;
	del(proot -> left);
	del(proot -> right);
	delete proot;
}
void huffman(){
	int n;cin>>n;
	char s[1010];
	int fe; 
	priority_queue<pTree,vector<pTree>,cmp> pque;	
		for(int i = 0;i < n;i++){
				cin>>s[i]>>fe;
				Tree *pt = new Tree;
				pt->freq = fe;
				pt->key = s[i];
				pque.push(pt);
			}
		while(pque.size() > 1){
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
		string ans;
		print_code(pque.top(),ans);
		del(pque.top());
}	
int main()
{
	huffman();
	return 0;
}
