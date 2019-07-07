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
    int u , v;
    double w;
    edge(double _w , int _u , int _v){
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
    return a.w - b.w < eps;
}
vector<edge> edges;
int rnk[MAX];
int par[MAX];
int forests;

void initi(int n){
    for(int i = 1 ; i <= n ; ++i)
        par[i] = i;
    memset(rnk , 1 , sizeof(rnk));
    forests = n;
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
    }
    else if(rnk[paru] > rnk[parv])
    {
        par[parv] = paru;
    }
    else{
        par[parv] = paru;
        rnk[paru]++;
    }
    forests--;
    return 1;
}

pair<double, double> points[505];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int k , n;
        sc(k);sc(n);
        initi(n);
        edges.clear();
        double res = -1;
        for(int i = 1 ; i <= n ; ++i){
            double x , y;
            scd(x);scd(y);
            points[i] = MP(x , y);
        }
        for(int i = 1 ; i <= n ; ++i){
            for(int j = i + 1 ; j <= n ; ++j){
                double dis = hypot(points[i].first - points[j].first , points[i].second - points[j].second);
                edges.pb({dis , i , j});
            }
        }
        sort(all(edges) , cmp);
        for(auto edge : edges){
            if(forests == k)
                break;
            int u = edge.u;
            int v = edge.v;
            double w = edge.w;
            if(_merge(u , v)){
                res = max(res , w);
            }
        }
        printf("%.2f\n" , res);
    }



return 0;
}
