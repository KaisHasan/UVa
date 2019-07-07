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

vector<int> adj[MAX];
vector<int> SC[MAX];
int vis[MAX];
vector<int> SCC;
int dfs_num[MAX] , dfs_low[MAX];
int dfsNumberCounter;
int numSCC;
map<string , int> encode;
map<int , string> decode;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    vis[u] = 1;
    SCC.pb(u);
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            tarjanSCC(v);
        }
        if(vis[v]){
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
    }

    if(dfs_num[u] == dfs_low[u]){
        ++numSCC;
        while(1){
            int v = SCC.back();
            SCC.pop_back();
            SC[numSCC].pb(v);
            vis[v] = 0;
            if(u == v){
                break;
            }
        }
    }
}


int main(){
    freopen("output.txt","w" , stdout);
int cases = 1;
while(1){
    memset(vis , 0 , sizeof(vis));
    memset(dfs_num , -1 ,sizeof(dfs_num));
    memset(dfs_low , 0 , sizeof(dfs_low));
    dfsNumberCounter = numSCC = 0;
    SCC.clear();
    encode.clear();
    decode.clear();
    int n , m;
    sc(n);sc(m);
    if(n == 0 && m == 0)
        break;
    int node = 1;
    for(int i = 0 ; i < m ; ++i){
        string s , t;
        cin >> s >> t;
        int u , v;
        if(!encode[s]){
            encode[s] = node++;
            decode[node - 1] = s;
        }
        if(!encode[t]){
            encode[t] = node++;
            decode[node - 1] = t;
        }
        u = encode[s];
        v = encode[t];
        if(u == v)
            continue;
        if(find(adj[u].begin() , adj[u].end() , v) != adj[u].end())
            continue;
        adj[u].pb(v);
    }
    printf("Calling circles for data set %d:\n" , cases++);
    for(int i = 1 ; i < node ; ++i){
        if(dfs_num[i] == -1){
            tarjanSCC(i);
        }
    }

    for(int i = numSCC ; i > 0 ; --i){
        for(int j = 0 ;j < SC[i].size() - 1; ++j)
        {
            cout<<decode[SC[i][j]]<<", ";
        }
        cout<<decode[SC[i][SC[i].size() - 1]]<<endl;
    }

    for(int i = 0 ;i <= numSCC ; ++i)
        SC[i].clear();

    for(int i = 0 ; i <= node ; ++i)
        adj[i].clear();
    blank;

}


return 0;
}
