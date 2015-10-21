#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
const int mx = 505;
int n, m;
bool g[mx][mx];
int main() {
    freopen("Graph.in", "r", stdin);
    freopen("Graph.out", "w", stdout);
    scanf("%d%d", &n, &m);
    srand(time(NULL));
    memset(g, 0, sizeof(g));
    int cnt = 0;
    double j1, j2;
    j1 = m * 1.0 / (n * (n + 1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            j2 = rand() / double(RAND_MAX);
            if(j2 < j1) {
                g[i][j] = 1;
                cnt++;
            }
        }
    cout << n << " " << cnt << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            if(g[i][j])
                cout << i << " " << j << endl;
    }
    return 0;
}