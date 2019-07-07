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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

struct edge{
    int u , v;
    double w;
    edge(){}
    edge(double a, int b , int c){
        w = a;
        u = b;
        v = c;
    }
    edge(const edge& temp){
        w = temp.w;
        u= temp.u;
        v = temp.v;
    }
};
bool cmp(edge a , edge b){

    return b.w - a.w > eps;
}
vector<pair<int , double> > MST[MAX];
vector<edge> edges;
int rnk[MAX];
int par[MAX];
pi points[MAX];

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
    if(parent(u) == parent(v))
        return 0;
    if(rnk[parent(u)] < rnk[parent(v)]){
        par[parent(u)] = parent(v);
        return 1;
    }
    else if(rnk[parent(u)] == rnk[parent(v)])
    {
        par[parent(v)] = parent(u);
        rnk[parent(u)] += 1;
        return 1;
    }
    else
    {
        par[parent(v)] = parent(u);
        return 1;
    }
}

double cal(pi a , pi b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int t;
sc(t);
while(t--){
    memset(rnk , 1 , sizeof(rnk));
    edges.clear();
    int n ;
    sc(n);;
    initi(n);
    for(int i = 0 ; i < n ;++i){
        int x ,y;
        sc(x);sc(y);
        points[i+1] = MP(x , y);
    }
    int q ;
    sc(q);
    for(int j = 0 ; j< q ; ++j){
        int x ,y;
        sc(x);sc(y);
        int f = _merge(x , y);
        MST[x].pb({y , 0});
        MST[y].pb({x , 0});
    }
    for(int i = 1 ; i <= n ;++i){
        for(int j = i + 1 ; j <= n ; ++j){
            edges.push_back(edge(cal(points[i] , points[j]) , i ,j ));
        }
    }
    sort(edges.begin() , edges.end() , cmp);
    int res= 0;
    for(int i = 0 ; i < edges.size() ; ++i){
        int u = edges[i].u;
        int v = edges[i].v;
        double w = edges[i].w;
        if(_merge(u , v)){
            MST[u].pb(MP(v , w));
            MST[v].pb(MP(u , w));
            res++;
            printf("%d %d\n" , u , v);
        }
    }
    if(!res){
        printf("No new highways need\n");
    }
    for(int i = 1 ; i <= n ; ++i)
        MST[i].clear();
    if(t)
        printf("\n");

    //cout<<setprecision(8)<<fixed<<cal(points[649] ,points[718])<<endl;
    //cout<<setprecision(8)<<fixed<<cal(points[657] ,points[727]);

}
return 0;
}
