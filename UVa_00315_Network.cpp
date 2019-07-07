#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 0.0000001;

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


int main(){

while(1){
    RootChildren = 0;
    dfsNumberCounter = 0;
    memset(dfs_num , -1 , sizeof(dfs_num));
    memset(dfs_low , 0 , sizeof(dfs_low));
    memset(dfs_parent , 0 , sizeof(dfs_parent));
    memset(articulation_vertex , 0 , sizeof(articulation_vertex));
    int res = 0;
    int n;
    sc(n);
    if(!n)
        break;
    while(1){
        int node;
        sc(node);
        if(!node)
            break;

        int v;
        char temp;
        do{
            scanf("%d%c" , &v , &temp);
            if(v == node)
                continue;
            adj[node].insert(v);
            adj[v].insert(node);
        }while(temp != '\n');
    }
    for(int i = 1 ; i <= n ; ++i){
        if(dfs_num[i] == -1){
            dfsRoot = i;
            RootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (RootChildren > 1);
        }
    }
    for(int i = 1 ; i <= n ; ++i)
        if(articulation_vertex[i])
            ++res;
    printf("%d\n" , res);

    for(int i = 1 ; i <= n ; ++i)
        adj[i].clear();



}

return 0;
}
