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
vpi adj[MAX];

vi dist;
pi Dijkstra(int st){
    dist.assign(n + 1 , inf);
    dist[st] = 0;
    priority_queue<pi , vpi , greater<pi> > pq;
    pq.push(MP(0,st));
    while(!pq.empty()){
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(w > dist[u])
            continue;
        for(auto v : adj[u]){
            if(v.second + w < dist[v.first]){
                dist[v.first] = v.second + w;
                pq.push(MP(dist[v.first] , v.first));
            }
        }
    }
    pi res;
    for(int i = 0 ; i <= n ; ++i){
        if(dist[i] == inf)
            continue;
        if(dist[i] > res.second){
            res.second = dist[i];
            res.first = i;
        }
    }
    return res;
}

void init(){
    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear();
    n = 0;
}

void sol(){
    int node = Dijkstra(1).first;
    int res = Dijkstra(node).second;
    printf("%d\n" , res);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
char cmd[100];

while(gets(cmd)){
    if(cmd[0] == '\0') {
        sol();
        init();
        continue;
    }
    int u , v , w;
    sscanf(cmd , "%d %d %d" , &u , &v , &w);
    n = max(n , u);
    n = max(n , v);
    adj[u].pb(MP(v,w));
    adj[v].pb(MP(u,w));
}
sol();

return 0;
}
