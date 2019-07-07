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
const int MAX = 30;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
double adj[MAX][MAX];
int par[MAX][MAX];
vi path;

void F_path(int i ,  int j){
    if(par[i][j] == -1)
        return;
    F_path(i ,par[i][j]);
    path.pb(j);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(sc(n) == 1){
        path.clear();
        mem(par , -1);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(i == j)
                    adj[i][i] = 1.0;
                else
                    cin>>adj[i][j];
            }
        }
        for(int k = 0 ; k < n ; ++k){
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if((adj[i][k] * adj[k][j]) - adj[i][j] > eps){
                        adj[i][j] = adj[i][k] * adj[k][j];
                        par[i][j] = par[k][j];
                    }
                }
            }
        }
        int mn = inf;
        int res = -1;
        for(int i = 0 ; i < n ; ++i){
            if(adj[i][i] > 1.01){
                path.clear();
                F_path(i , i);
                path.pb(i);
                if(path.size() < mn){
                    mn = path.size();
                    res = i;
                }
            }
        }
        if(res == -1)
            printf("no arbitrage sequence exists\n");
        else{
            path.clear();
            F_path(res , par[res][res]);
            path.pb(res);
            printf("%d" , path[0] + 1);
            for(int i = 1 ; i < (int)path.size() ; ++i){
                printf(" %d" , path[i] + 1);
            }
            blank;
        }

    }



return 0;
}
