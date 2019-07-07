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

vi adj[MAX];

int vis[MAX];
void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u])
        dfs(v);
}
set<int> nodes;
int in[MAX] , out[MAX];
int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;

    while(1){
        bool test = true;
        int u , v;
        sc(u);sc(v);
        if(u < 0 && v < 0)
            break;
        if(u + v != 0){
            adj[u].pb(v);
            nodes.insert(u);
            nodes.insert(v);
            ++out[u];
            ++in[v];
            while(1){
                sc(u);sc(v);
                if(u + v == 0)
                    break;
                adj[u].pb(v);
                nodes.insert(u);
                nodes.insert(v);
                ++out[u];
                ++in[v];
            }
            int cnt = 0;
            int root;
            for(auto x : nodes){
                if(in[x] > 1){
                    test = false;
                    break;
                }
                else if(!in[x]){
                    ++cnt;
                    root = x;
                }
                if(cnt > 1){
                    test = false;
                    break;
                }
            }
            if(test){
                dfs(root);
                for(auto x : nodes){
                    if(!vis[x]){
                        test = false;
                        break;
                    }
                }
            }
        }
        if(test)
            printf("Case %d is a tree." , ++cases);
        else
            printf("Case %d is not a tree." , ++cases);
        blank;
        for(auto x : nodes){
            in[x] = out[x] = vis[x] = 0;
            adj[x].clear();
        }
        nodes.clear();

    }




return 0;
}
