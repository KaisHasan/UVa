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

vpi adj[MAX];
int dist[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int n , m;
        sc(n);sc(m);
        for(int i = 0 ; i < m ; ++i){
            int u , v , w;
            sc(u);sc(v);sc(w);
            adj[u].pb(MP(v , w));
        }
        fill(dist , dist + n , inf);
        for(int k = 0 ; k < n - 1 ; ++k){
            for(int u = 0 ; u < n ; ++u){
                for(auto v : adj[u]){
                    dist[v.first] = min(dist[v.first] , dist[u] + v.second);
                }
            }
        }
        bool hasNegativeCycle = false;
        for(int u = 0 ; u < n ; ++u){
            for(auto v : adj[u]){
                if(dist[u] + v.second < dist[v.first]){
                    hasNegativeCycle = true;
                    break;
                }
            }
            if(hasNegativeCycle)
                break;
        }
        if(hasNegativeCycle)
            printf("possible\n");
        else
            printf("not possible\n");

        for(int i = 0 ;i < n ; ++i)
            adj[i].clear();
    }



return 0;
}
