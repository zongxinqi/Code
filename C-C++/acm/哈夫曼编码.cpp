#include<bits/stdc++.h>
using namespace std;
int cal(char x){
	return x - 'a' + 1;
}
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
		cout<<proot->key<<ans<<endl;
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
	string s;cin>>s;
	priority_queue<pTree,vector<pTree>,cmp> pque;	
		int a[30] = {0};
		for(int i = 0;i < s.length();i++)a[cal(s[i])]++;
		for(int i = 0;i < 26;i++){
			if(a[i]){
				Tree *pt = new Tree;
				pt->freq = a[i];
				pt->key = i - 1 + 'a';
				pque.push(pt);
			}
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
	int n;
	while(cin>>n){
		for(int i = 0;i < n;i++) huffman();
	}
	return 0;
}
