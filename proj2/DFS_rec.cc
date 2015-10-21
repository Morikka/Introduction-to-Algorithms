#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <sys/time.h>
using namespace std;
const int mx = 505;
const int NIL = 0x3f3f3f3f;
vector<int> g[mx];
int n, m, t;
int color[mx], d[mx], f[mx], p[mx];
double getTime(void) {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec / 1000000.0;
}
void input() {
    int x, y;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }
}
void dfs_visit(int u) {
    t++;
    d[u] = t;
    color[u] = 1;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(color[v] == 0) {
            p[v] = u;
            dfs_visit(v);
        }
    }
    color[u] = 2;
    t++;
    f[u] = t;
}
void dfs() {
    for(int i = 1; i <= n; i++) {
        color[i] = 0;
        p[i] = NIL;
    }
    t = 0;
    for(int i = 1; i <= n; i++)
        if(color[i] == 0)
            dfs_visit(i);
}
int main() {
    freopen("Graph.out", "r", stdin);
    freopen("DFS_rec.out", "w", stdout);
    input();
    double startTime = getTime();
    for(int i = 0; i < 10000; i++)
        dfs();
    double loadTime = getTime() - startTime;
    cout << loadTime << endl;
    return 0;
}