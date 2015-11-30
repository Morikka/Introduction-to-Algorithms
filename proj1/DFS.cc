#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int mn = 30, mx = 300;
vector<int> nod[mn];
int cnt;
void dfs(int p, int pos, bool b[]) {
    for(int i = 0; i < nod[pos].size(); i++) {
        int nxt = nod[pos][i];
        if(nxt == p) {
            cnt++;
            continue;
        }
        if(nxt < p)continue;
        if(b[nxt])continue;
        b[nxt] = true;
        dfs(p, nxt, b);
        b[nxt] = false;
    }
}
int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%d%d", &x, &y);
        nod[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) {
        bool b[mn];
        memset(b, 0, sizeof(b));
        b[i] = true;
        dfs(i, i, b);
    }
    printf("The circle number of the picture is %d\n", cnt);
    return 0;
}
