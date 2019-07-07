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
const ll inf = 1e14+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

vector<pair<int , ll> > adj[MAX];
ll t[MAX];
ll calc(int u , int v){
    return (t[v] - t[u])*(t[v] - t[u])*(t[v] - t[u]);
}
int n;
ll dist[MAX];
//int vis[MAX];
int Neg[MAX];
//void dfs(int u){
//    vis[u] = 1;
//    Neg[u] = 1;
//    for(auto v : adj[u]){
//        if(!vis[v.first])
//            dfs(v.first);
//    }
//}
void Bellman(int st){
    mem(Neg , 0);
//    mem(vis , 0);
    fill(dist , dist + n + 3 , inf);
    dist[st] = 0;
    for(int i = 0 ; i < n - 1; ++i){
        for(int u = 1 ; u <= n ; ++u){
            for(auto v : adj[u]){
                if(dist[u] != inf)
                    dist[v.first] = min(dist[v.first] , dist[u] + v.second);
            }
        }
    }
    for(int u = 1 ; u <= n ; ++u){
        for(auto v : adj[u]){
            if(dist[u] + v.second < dist[v.first] && dist[u] != inf){
                dist[v.first] = -inf;
                Neg[v.first] = 1;
            }
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
    while(sc(n) == 1){
        for(int i = 1; i <= n ; ++i){
            scl(t[i]);
        }
        int m;sc(m);
        for(int i = 0; i < m ; ++i){
            int u , v;
            sc(u);sc(v);
            ll w = calc(u , v);
            adj[u].pb(MP(v , w));
        }
        int q;
        sc(q);
        Bellman(1);
        printf("Set #%d\n" , ++cases);
        while(q--){
            int des;
            sc(des);
            ll res = dist[des];
            if(res < 3 || Neg[des] || dist[des] == inf)
                printf("?\n");
            else
                printf("%lld\n" , res);
        }
        for(int i = 1 ; i <= n ; ++i)
            adj[i].clear();
    }



return 0;
}
