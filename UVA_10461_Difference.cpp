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
const int N = 505;
bool g[N][N], gb[N][N], mk1[N], mk2[N];
int v[N];

void dfs1(int u, int n)
{
    mk1[u] = 1;
    for(int i = 1; i <= n; i++)
        if(!mk1[i] && g[u][i])
            dfs1(i, n);
}

void dfs2(int u, int n)
{
    mk2[u] = 1;
    for(int i = 1; i <= n; i++)
        if(!mk2[i] && gb[u][i])
            dfs2(i, n);
}

int main()
{
    int n, m, a, b, cas = 1;
    while(scanf("%d %d", &n, &m), n + m)
    {
        memset(g, 0, sizeof(g));
        memset(gb, 0, sizeof(gb));

        for(int i = 1; i <= n; i++)
            scanf("%d", &v[i]);

        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            g[a][b] = 1;
            gb[b][a] = 1;
        }
        scanf("%d", &m);
        printf("Case #%d:\n", cas++);
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &a);
            memset(mk1, 0, sizeof(mk1));
            memset(mk2, 0, sizeof(mk2));
            dfs1(a, n);
            dfs2(a, n);
            int count = 0;
            for(int j = 1; j <= n; j++)
            {
                if(!mk1[j] && !mk2[j])
                {
                    count += v[j];
                }
            }
            printf("%d\n", count);
        }
        puts("");
    }
    return 0;
}
