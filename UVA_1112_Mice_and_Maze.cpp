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

vpi adj[111];
int dist[111];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int st;sc(st);
        --st;
        int timer;sc(timer);
        int m;sc(m);
        while(m--){
            int u , v , w;
            sc(u);sc(v);sc(w);
            --u;
            --v;
            adj[v].pb(MP(u,w));
        }
        priority_queue<pi , vpi , greater<pi> > pq;
        pq.push(MP(0 , st));
        fill(dist , dist + n + 1 , inf);
        dist[st] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if(w > dist[u])
                continue;
            for(auto node : adj[u]){
                if(dist[u] + node.second < dist[node.first]){
                    dist[node.first] = dist[u] + node.second;
                    pq.push(MP(dist[node.first] , node.first));
                }
            }
        }
        int res = 0;
        for(int i = 0 ; i < n ; ++i){
            if(dist[i] <= timer)
                ++res;
        }
        printf("%d\n" , res);
        for(int i = 0 ; i <= n ; ++i)
            adj[i].clear();
        if(t)
            blank;
    }



return 0;
}
