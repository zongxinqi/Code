#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
const int MAX = 1010;
struct moon {
    double t;
    double money;
    double moneymax;
}M[MAX];
int cmp(const void *a, const void *b) {
    return (*(moon*)a).money > (*(moon*)b).money ? -1 : 1;
}
int main() {
    int n;
    double tmax;
    scanf("%d%lf", &n, &tmax);
    double ans=0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &M[i].t);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &M[i].moneymax);
        M[i].money = M[i].moneymax / M[i].t;
    }
    qsort(M, n, sizeof(M[0]), cmp);
    for (int i = 0; i < n&&tmax>0; i++) {
        if (M[i].t < tmax) {
            ans += M[i].moneymax;
            tmax -= M[i].t;
        }
        else {
            ans += M[i].money*tmax;
            tmax = 0;
        }
    }
    printf("%.2lf", ans);
    return 0;
}
