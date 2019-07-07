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
#define INF 1e9
#define EPS 1e-9
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;


int n;
vi adj[MAX];
vi dist , up;
set<int> worst;
vi best;
pi BFS(int st){
    dist.assign(n + 1 , -1);
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    pi res(0,0);
    for(int i = 1 ; i <= n ; ++i){
        if(dist[i] > res.second){
            res.second = dist[i];
            res.first = i;
        }
    }
    int mx = res.second;
    for(int i = 1 ; i <= n ; ++i)
        if(dist[i] == mx)
            worst.insert(i);
    return res;
}

void dfs(int u , int par = -1){
    int mx = -1;
    for(auto v : adj[u]){
        if(v != par){
            dfs(v , u);
            mx = max(mx , up[v]);
        }
    }
    up[u] = mx + 1;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(sc(n) != EOF){
        up.assign(n + 1 , 0);
        worst.clear();
        best.clear();
        for(int i = 1 ; i <= n ; ++i){
            int k;
            sc(k);
            while(k--){
                int x;sc(x);
                adj[i].pb(x);
            }
        }
        int node = BFS(1).first;
        int res = BFS(node).second;
        dfs(node);
        for(int i = 1 ; i <= n ; ++i)
            if(up[i] == res / 2)
                best.pb(i);
            else if(res & 1){
                if(up[i] == res / 2 + 1)
                    best.pb(i);
            }

        printf("Best Roots  :");
        for(auto x : best){
            printf(" %d" , x);
        }
        blank;
        printf("Worst Roots :");
        for(auto x : worst){
            printf(" %d" , x);
        }
        blank;
        for(int i = 1 ; i <= n ; ++i)
            adj[i].clear();
    }



return 0;
}
