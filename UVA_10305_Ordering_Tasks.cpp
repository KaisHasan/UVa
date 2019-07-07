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
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

vector<int> adj[MAX];
int vis[MAX];
vector<int> topo;
int n;
void dfs(int v){
    vis[v] = 1;
    for(auto u : adj[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
    topo.pb(v);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        memset(vis , 0 , sizeof(vis));
        topo.clear();
        sc(n);
        int m;
        sc(m);
        if(!n && !m)
            break;
        for(int i = 0 ; i < m ; ++i){
            int u , v;
            sc(u);
            sc(v);
            adj[u].pb(v);
        }
        for(int i = 1 ; i <= n ; ++i){
            if(!vis[i])
                dfs(i);
        }
        for(int i = n - 1 ; i > 0; --i){
            printf("%d " , topo[i]);
        }
        printf("%d" , topo[0]);
        blank;
        for(int i= 1 ; i <= n ; ++i)
            adj[i].clear();
    }



return 0;
}
