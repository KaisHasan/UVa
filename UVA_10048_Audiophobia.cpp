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

struct edge{
    int w , u , v;
    edge(int _w = 0, int _u = 0, int _v = 0){
        w = _w;
        u = _u;
        v = _v;
    }
    edge(const edge& temp){
        w = temp.w;
        u = temp.u;
        v = temp.v;
    }
};
bool cmp(edge a , edge b){
    return a.w < b.w;
}
vector<pi> MST[2*MAX];
vector<edge> edges;
int rnk[2*MAX];
int par[2*MAX];

void initi(int n){
    for(int i = 1 ; i <= n ; ++i)
        par[i] = i;
    memset(rnk , 1 , sizeof(rnk));
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}

bool _merge(int u , int v){
    int paru = parent(u) , parv = parent(v);
    if(paru == parv)
        return 0;
    if(rnk[paru] < rnk[parv]){
        par[paru] = parv;
        return 1;
    }
    else if(rnk[paru] > rnk[parv])
    {
        par[parv] = paru;
        return 1;
    }
    else{
        par[parv] = paru;
        rnk[paru]++;
        return 1;
    }
}

int res[123][123];
int vis[123];
int st;
void dfs(int v , int mx){
    vis[v] = 1;
    if(res[st][v] == -1)
        res[st][v] = mx;
    for(auto node : MST[v]){
        if(!vis[node.first]){
            dfs(node.first , max(mx , node.second));
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
    while(1){
        int n , m , q;
        sc(n);sc(m);sc(q);
        if(!n && !m && !q)
            break;
        if(cases)
            blank;
        initi(n);
        edges.clear();
        for(int i = 0 ;i < m ; ++i){
            int u , v , w;
            sc(u);sc(v);sc(w);
            edges.pb(edge(w , u , v));
        }
        sort(all(edges) , cmp);
        for(auto e : edges){
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if(_merge(u , v)){
                MST[u].pb(MP(v,w));
                MST[v].pb(MP(u,w));
            }
        }
        mem(res , -1);
        for(int i = 1 ; i <= n ; ++i){
            mem(vis , 0);
            st = i;
            dfs(st , 0);
        }
        printf("Case #%d\n" , ++cases);
        for(int i = 0 ; i < q ; ++i){
            int u , v;
            sc(u);sc(v);
            int ans = res[u][v];
            if(ans == -1)
                printf("no path\n");
            else
                printf("%d\n" , ans);
        }
        for(int i = 1 ; i <= n ; ++i)
            MST[i].clear();
    }



return 0;
}
