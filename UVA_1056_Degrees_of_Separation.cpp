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
const int MAX = 100;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
int adj[MAX][MAX];
map<string , int> trans;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
    while(1){
        int m;
        sc(n);sc(m);
        if(!n && !m)
            break;
        trans.clear();
        for(int i = 0 ; i < MAX ; ++i)
            for(int j = 0 ; j < MAX ; ++j)
                adj[i][j] = inf;
        int cur = 0;
        for(int i = 0 ; i < m ; ++i){
            string s , t;
            cin>>s>>t;
            if(trans.find(s) == trans.end())
                trans[s] = cur++;
            if(trans.find(t) == trans.end())
                trans[t] = cur++;
            int u = trans[s];
            int v = trans[t];
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        for(int k = 0 ; k < n ; ++k){
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0; j < n ; ++j){
                    adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }
        int mx = -1;
        printf("Network %d: " , ++cases);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(i == j)
                    continue;
                if(adj[i][j] == inf)
                    goto dis;
                mx = max(mx , adj[i][j]);
            }
        }
        printf("%d\n\n" , mx );
        continue;
    dis:
        printf("DISCONNECTED\n\n");
    }



return 0;
}
