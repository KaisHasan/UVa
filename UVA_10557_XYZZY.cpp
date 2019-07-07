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

vpi adj[MAX];
int dist[MAX];
vi save[MAX];
int values[MAX];
int vis[MAX];
int check;
void dfs(int u){
    check = max(check , u);
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v.first])
            dfs(v.first);
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
    while(1){
        int n;
        sc(n);
        if(n == -1)
            break;
        ++cases;
        for(int i = 0 ; i < n ; ++i){
            sc(values[i]);
            int m;sc(m);
            while(m--){
                int x;sc(x);
                --x;
                save[i].pb(x);
            }
        }
        for(int i = 0 ; i < n ; ++i){
            for(auto node : save[i]){
                adj[i].pb(MP(node , -values[node]));
            }
        }
        fill(dist, dist + n + 1 , inf);
        dist[0] = -100;
        for(int i = 0 ; i < n - 1 ; ++i){
            for(int u = 0 ; u < n ; ++u){
                for(auto v : adj[u]){
                    if(dist[u] + v.second >= 0)
                        continue;
                    dist[v.first] = min(dist[v.first] , dist[u] + v.second);
                }
            }
        }
        if(dist[n-1] <= 0){
            printf("winnable\n");
        }
        else{
            bool NegativeCycle = false;
            for(int u = 0 ; u < n ; ++u){
                for(auto v : adj[u]){
                    if(dist[u] + v.second >= 0)
                        continue;
                    if(dist[u] + v.second < dist[v.first]){
                        NegativeCycle = true;
                        mem(vis , 0);
                        check = -1;
                        dfs(u);
                        if(check != n - 1)
                            NegativeCycle = false;
                    }
                }
            }
            if(NegativeCycle){
                printf("winnable\n");
            }
            else
                printf("hopeless\n");
        }
        for(int i = 0 ;i <= n ; ++i)
            adj[i].clear();
        for(int i = 0 ; i <= n ; ++i)
            save[i].clear();
    }



return 0;
}
