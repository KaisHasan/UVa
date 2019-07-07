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

vpi adj[MAX][2];
ll dist[MAX][2];
int n , m;
void dijkstra(int st , int id){
    for(int i = 0 ;i <= n ; ++i)
        dist[i][id] = inf;
    dist[st][id] = 0;
    priority_queue<pi , vpi,  greater<pi> > pq;
    pq.push(MP(0 , st));
    while(!pq.empty()){
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(w > dist[u][id])
            continue;
        for(auto v : adj[u][id]){
            if(dist[u][id] + v.second < dist[v.first][id]){
                dist[v.first][id] = dist[u][id] + v.second;
                pq.push(MP(dist[v.first][id] , v.first));
            }
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int cases;
    sc(cases);
    while(cases--){
        vector<pair<pi , int> > edges;
        edges.clear();
        int s , t , p;
        sc(n);sc(m);sc(s);sc(t);sc(p);
        --s;--t;
        for(int i = 0 ; i < m ; ++i){
            int u , v , w;
            sc(u);sc(v);sc(w);
            --u;--v;
            adj[u][0].pb(MP(v ,w));
            adj[v][1].pb(MP(u ,w));
            edges.pb(MP(MP(u , v) , w));
//            edges.pb(MP(MP(v , u) , w));
        }
        dijkstra(s ,0);
        dijkstra(t ,1);
        int res = -1;
        for(auto e : edges){
            int u = e.first.first;
            int v = e.first.second;
            int w = e.second;
//            printf("dist[%d] == %lld  , dist[%d] ==  %lld , w ==  %d\n" ,u, dist[u][0],v , dist[v][1] , w);
            if(dist[u][0] + w + dist[v][1] <= p){
                res = max(res , w);
            }
        }
        printf("%d\n" , res);
        for(int i = 0; i < 2 ; ++i){
            for(int j = 0 ; j < n ; ++j)
                adj[j][i].clear();
        }
    }



return 0;
}
