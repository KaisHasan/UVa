#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scd(a) scanf("%lf" , &a)
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 0.0000001;

set<int> adj[MAX];
int vis[MAX] , exist[MAX];

void dfs(int v){
    vis[v] = 1;
    for(auto i : adj[v]){
        if(!vis[i])
            dfs(i);
    }
}

void _merge(int u , int v){
    if(u == v)
        return;
    if(adj[u].find(v) == adj[u].end()){
        adj[u].insert(v);
        adj[v].insert(u);
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);

    int t;
    sc(t);
    while(t--){
        memset(vis , 0 , sizeof(vis));
        memset(exist , 0 , sizeof(exist));
        char c;
        cin>>c;
        int n = int(c) - int('A') + 1;
        string s;
        cin.ignore();
        while(1){
            s.clear();
            getline(cin , s);
            if(s.empty())
                break;
            int u = int(s[0]) - int('A');
            int v = int(s[1]) - int('A');
            _merge(u , v);
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            if(!vis[i]){
                ++cnt;
                dfs(i);
            }
        }
        printf("%d" , cnt);
        printf("\n");
        if(t)
            printf("\n");
        for(int i = 0 ; i < n ; ++i)
            adj[i].clear();
    }



return 0;
}
