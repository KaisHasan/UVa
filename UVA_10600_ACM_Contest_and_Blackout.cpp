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
};
bool cmp(edge a , edge b){
    return a.w < b.w;
}
vector<pi> MST[MAX];
vector<edge> edges;
int rnk[MAX];
int par[MAX];

void initi(int n){
    for(int i = 1 ; i <= n ; ++i)
        par[i] = i;
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
int fu , fv;
bool valid(int x , int y){
    if(x == fu && y == fv)
        return 0;
    if(y == fu && x == fv)
        return 0;
    return 1;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
while(t--){
    memset(rnk , 1 , sizeof(rnk));
    edges.clear();
        int n , m;
        sc(n);sc(m);
        initi(n);
        for(int i = 0 ; i < m ;++i){
            int w , u , v;
            sc(u);sc(v);sc(w);
            edges.pb({w , u , v});
        }
        sort(edges.begin() , edges.end() , cmp);
        int sum1 = 0;
        vector<pi> MST_edges;
        for(auto i : edges){
            if(_merge(i.u , i.v)){
                MST[i.u].pb({i.v , i.w});
                MST[i.v].pb({i.u , i.w});
                sum1 += i.w;
                MST_edges.pb(MP(i.u , i.v));
            }
        }
        int sum2 = inf;
        for(int i = 0 ; i < MST_edges.size() ; ++i){
            initi(n);
            memset(rnk , 1 , sizeof(rnk));
            fu = MST_edges[i].first;
            fv = MST_edges[i].second;
            int res = 0;
            int test = 0;
            for(auto i : edges){
                if(valid(i.u , i.v) && _merge(i.u , i.v)){
                    res += i.w;
                    ++test;
                }
            }
            if(test == n - 1) // test if it a tree or not
                sum2 = min(sum2 , res);
        }

        printf("%d %d" , sum1 , sum2);
        blank;
        for(int i = 0 ; i <= n ; ++i)
            MST[i].clear();
        MST_edges.clear();
}

return 0;
}
