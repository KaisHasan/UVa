#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<long long , long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
//vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int g[512][512], indeg[512];
void topo(int n) {
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0)
            Q.push(i);
    }
    int r[512], rt = 0, u;
    while (!Q.empty()) {
        u = Q.front(), Q.pop();
        r[rt++] = u;
        for (int i = 1; i <= n; i++) {
            if (g[u][i]) {
                if (--indeg[i] == 0)
                    Q.push(i);
            }
        }
    }
    if (rt != n) {
        puts("IMPOSSIBLE");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", r[i], i == n-1 ? '\n' : ' ');
    }
}
int main() {
    int testcase, rank[512];
    int n, m, x, y;
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &rank[i]);

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                g[i][j] = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                g[rank[i]][rank[j]] = 1;

        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            swap(g[x][y], g[y][x]);
        }

        for (int i = 1; i <= n; i++) {
            indeg[i] = 0;
            for (int j = 1; j <= n; j++)
                indeg[i] += g[j][i];
        }
        topo(n);
    }
    return 0;
}
