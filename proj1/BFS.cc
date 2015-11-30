#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int mn = 30, mx = 300;
int cnt;
struct node {
    int p;
    bool b[mn];
} tmp;
queue<node> q;
void bfs(int pos) {
    tmp.p = pos;
    memset(tmp.b, 0, sizeof(tmp.b));
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.front();
        q.pop();
    }
}
int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    puts("TEST");
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%d%d", &x, &y);
        //nod[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) {
        bfs(i);
    }
    return 0;
}
