#include <iostream>
#include <queue>
using namespace std;
#define max 200

int MST; //  最小生成树
int Nodenum;
int father[max];
struct edge {
  int from;
  int to;
  int cost;
  friend bool operator < (const edge& a, const edge& b) {
    return a.cost > b.cost;
  }
};
// to find the minimal distance of edge.
priority_queue<edge> SQ;
/**
 *  to find the final father of the node.
 *
 *  @param x node index.
 *
 *  @return father index.
 */
int find(int x) {
  return x == father[x] ? x : find(father[x]);
}
int Kruskal() {
  MST = 0;
  for (int i = 1; i <= Nodenum; i++) {
    father[i] = i;
  }
  int num = 0;
  while (!SQ.empty() && num != Nodenum - 1) {
    edge temp = SQ.top();
    SQ.pop();
    int father_x = find(temp.from);
    int father_y = find(temp.to);
    if (father_x != father_y) {
      father[father_y] = find(father[father_x]);
      MST += temp.cost;
      num++;
    }
  }
  /**
   *  Let every index has their final father.
   */
  for (int i = 1; i <= Nodenum; i++) {
    father[i] = find(father[i]);
  }
  return MST;
}
bool judge() {
  int flag = father[1];
  for (int i = 2; i != Nodenum + 1; i++) {
    if (flag != find(father[i])) {
      return false;
    }
  }
  return true;
}
int main() {
  int edgeNum; //  边总数
  cin >> Nodenum;
  cin >> edgeNum;
  while (!SQ.empty()) {
    SQ.pop();
  }
  while (edgeNum--) {
    int from; int to; int cost;
    cin >> from >> to >> cost;
    edge a;
    a.from = from;
    a.to = to;
    a.cost = cost;
    SQ.push(a);
  }
  int MST = Kruskal();
  if (judge()) {
    cout << MST << endl;
  } else {
    cout << "Don't exist!" << endl;
  }
  return 0;
}
