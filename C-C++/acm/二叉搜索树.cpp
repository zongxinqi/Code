#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <string>  
#include <iostream>  
#include <unordered_map>  
using namespace std;  
  
const int maxn = 100 + 10;  
  
unordered_map<int,int>mp;  
  
int a[maxn];  
int lch[maxn], rch[maxn],dep[maxn];  
int fa[maxn];  
int cnt = 1;  
int root;  
  
void dfs(int x, int d){  
    if (x == -1) return ;  
  
    dep[x] = d;  
    dfs(lch[x],d+1);  
    dfs(rch[x],d+1);  
}  
void insert(int x){  
    int cur = 0;  
    while(1){  
        if (x < a[cur]){  
            if (lch[cur] == -1){  
                a[cnt] = x;  
                fa[cnt] = cur;  
                mp[x] = cnt;  
                lch[cur] = cnt++;  
                return;  
            }  
            else {  
                fa[lch[cur] ] = cur;  
                cur = lch[cur];  
            }  
        }  
        else {  
            if (rch[cur] == -1){  
                a[cnt] = x;  
                fa[cnt] = cur;  
                mp[x] = cnt;  
                rch[cur] = cnt++;  
                return;  
            }  
            else {  
                fa[rch[cur] ] = cur;  
                cur = rch[cur];  
            }  
        }  
    }  
}  
int find(int x){  
    if (x== root) return 0;  
    if (!mp.count(x)) return -1;  
    return mp[x];  
}  
  
char s[1000];  
  
int main(){  
    int n,x;  
    scanf("%d",&n);  
    memset(lch,-1,sizeof lch);  
    memset(rch,-1,sizeof rch);  
    scanf("%d",&root);  
    a[0] = root; fa[0] = -1;  
    for (int i = 1; i < n; ++i){  
        scanf("%d",&x);  
        insert(x);  
    }  
  
    int q;  
    scanf("%d",&q);  
  
    dfs(0,0);  
    int u,v;  
    while(q--){  
        scanf("%d",&u);  
        scanf("%s",s);  
        if (strcmp(s,"is") == 0){  
            scanf("%s",s);  
            scanf("%s",s);  
//            cin >> s; cin >> s;  
            if (!strcmp("root",s)){  
                if (u == root) {  
                    puts("Yes");  
                }  
                else puts("No");  
  
            }  
            else if (!strcmp(s,"parent")){  
                scanf("%s",s); scanf("%d",&v);  
                int pos = find(v);  
                if (pos == -1) {  
                    puts("No");  
                    continue;  
                }  
                int fap = fa[pos];  
                if (v == root || a[fap] != u){  
                    puts("No");  
                }  
                else puts("Yes");  
            }  
            else if (!strcmp(s,"left")){  
                scanf("%s",s);  
                scanf("%s",s);  
                scanf("%d",&v);  
//                cin >> s; cin >> s; cin >>v;  
                int pos = find(v);  
                if (pos == -1) {  
                    puts("No");  
                    continue;  
  
                }  
                int lp = lch[pos];  
                if (lp == -1 || a[lp] != u){  
                    puts("No");  
                }  
                else puts("Yes");  
  
            }  
            else {  
                scanf("%s",s);  
                scanf("%s",s);  
                scanf("%d",&v);  
//                cin >> s; cin >> s; cin >>v;  
                int pos = find(v);  
  
                if (pos == -1){  
                    puts("No");  
                    continue;  
  
                }  
  
                int lp = rch[pos];  
                if (lp == -1 || a[lp] != u){  
                    puts("No");  
                }  
                else puts("Yes");  
  
            }  
  
  
        }  
        else {  
            scanf("%d",&v);  
//            cin >>v;  
            scanf("%s",s);  
            scanf("%s",s);  
//            cin >>s; cin >> s;  
            if (!strcmp("on",s)){  
                scanf("%s",s);  
                scanf("%s",s);  
                scanf("%s",s);  
//                cin >> s ; cin >> s; cin >> s;  
                int p1 = find(u);  
                int p2 = find(v);  
                if (p1 == -1||p2 == -1) {  
                    puts("No");  
                    continue;  
  
                }  
                if (dep[p1] != dep[p2]) puts("No");  
                else puts("Yes");  
            }  
            else {  
                int p1 = find(u);  
                int p2 = find(v);  
  
  
                if (p1 == -1 || p2 == -1){  
                    puts("No");  
                    continue;  
  
                }  
                if (fa[p1] != fa[p2]) puts("No");  
                else puts("Yes");  
            }  
        }  
  
    }  
  
    return 0;  
} 
