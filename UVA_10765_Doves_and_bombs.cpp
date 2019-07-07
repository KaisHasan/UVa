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

set<int> adj[MAX];
int dfs_num[MAX] , dfs_low[MAX];
int dfs_parent[MAX];
int dfsNumberCounter;
int articulation_vertex[MAX];
int dfsRoot , RootChildren;

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            dfs_parent[v] = u;
            if(u == dfsRoot)
                ++RootChildren;
            articulationPointAndBridge(v);
            if(dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
        else if(v != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u] , dfs_num[v]);
        }
    }
}
int vis[MAX];
int bomb;
void dfs(int v){
    vis[v] = 1;
    for(auto node : adj[v])
        if(!vis[node] && node != bomb)
            dfs(node);
}

bool cmp(pi a , pi b){
    if(a.second > b.second)
        return 1;
    else if(a.second < b.second)
        return 0;
    else
        return a.first < b.first;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

while(1){
    RootChildren = 0;
    dfsNumberCounter = 0;
    memset(dfs_num , -1 , sizeof(dfs_num));
    memset(dfs_low , 0 , sizeof(dfs_low));
    memset(dfs_parent , 0 , sizeof(dfs_parent));
    memset(articulation_vertex , 0 , sizeof(articulation_vertex));

    int n , m;
    sc(n);sc(m);
    if(!n && !m)
        break;
    while(1){
        int u , v;
        sc(u);sc(v);
        if(u == -1 && v == -1)
            break;
        if(u == v)
            continue;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for(int i = 0 ; i < n ; ++i){
        if(dfs_num[i] == -1){
            RootChildren = 0;
            dfsRoot = i;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (RootChildren > 1);
        }
    }
    vector<pi> res;
    for(int i = 0 ; i < n ; ++i){
        if(articulation_vertex[i]){
            memset(vis , 0 , sizeof(vis));
            int cnt = 0;
            bomb = i;
            for(int j = 0 ; j < n ; ++j){
                if(!vis[j] && j != i){
                    ++cnt;
                    dfs(j);
                }
            }
            res.pb(make_pair(i , cnt));
        }
    }
    sort(res.begin() , res.end() , cmp);
    for(int i = 0 ; i < min(m , int(res.size())) ; ++i){
        printf("%d %d\n" , res[i].first , res[i].second);
    }
    for(int j = 0 , i = res.size() ; i < m && j < n;  ++j){
        if(!articulation_vertex[j]){
            printf("%d 1\n" , j);
            ++i;
        }
    }
    blank;
    res.clear();
    for(int i = 0 ; i < n ; ++i)
        adj[i].clear();
}


return 0;
}
