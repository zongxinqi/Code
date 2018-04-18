#include<bits/stdc++.h>
#define MaxInt 100
#define MaxEle 120
using namespace std;
int map[MaxEle][MaxEle];
int visited[MaxEle];
int distance_low[MaxEle];
int prim(int n) {
  int pos, min, MST = 0;
  visited[1] = 1;
  pos = 1;
  for (int i = 2; i <= n; i++) {
    if (map[pos][i] == 0) {
      distance_low[i] = MaxInt;
    } else {
      distance_low[i] = map[pos][i];
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    min = MaxInt;
    for (int j = 1; j <= n; j++) {
      if (visited[j] == 0 && min > distance_low[j]) {
        min = distance_low[j];
        pos = j;
      }
    }
    visited[pos] = 1;
    MST += min;
    for (int j = 1; j <= n; j++) {
      if (visited[j] == 0 && distance_low[j] > map[pos][j]) {
        if (map[pos][j] != 0) {
          distance_low[j] = map[pos][j];
        }
      }
    }
  }
  return MST;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(map, MaxInt, sizeof(map));
    for (int i = 1; i != n + 1; i++) {
      for (int j = 1; j != n + 1; j++) {
        int ele;
        cin >> ele;
        map[i][j] = map[j][i] = ele;
      }
    }
    int ans = prim(n);
    cout << ans << endl;
  }
  return 0;
}
