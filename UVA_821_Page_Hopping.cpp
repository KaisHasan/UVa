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
const int MAX = 1000;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
int adjMat[MAX][MAX];
int exist[MAX];
vi nodes;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
    while(1){
        n = 0;
        for(int i = 0 ; i <= 101 ; ++i){
            for(int j = 0 ; j <= 101 ; ++j){
                adjMat[i][j] = inf;
            }
        }
        mem(exist , 0);
        nodes.clear();
        while(1){
            int u , v;
            sc(u);sc(v);
            if(!u && !v)
                break;
            ++n;
            adjMat[u][v] = 1;
            if(!exist[u]){
                exist[u] = 1;
                nodes.pb(u);
            }
            if(!exist[v]){
                exist[v] = 1;
                nodes.pb(v);
            }
        }
        if(!n)
            break;
        n = nodes.size();
        int sum = 0;
        for(int k = 0 ; k < n ; ++k){
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    int u = nodes[i];
                    int v = nodes[j];
                    int _k = nodes[k];
                    adjMat[u][v] = min(adjMat[u][v] , adjMat[u][_k] + adjMat[_k][v]);
                }
            }
        }
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                int u = nodes[i];
                int v = nodes[j];
                if(u == v)
                    continue;
                sum += adjMat[u][v];
//                printf("u == %d , v == %d , dist == %d\n" , u , v , adjMat[u][v]);
            }
        }
        int num = n * (n-1);
        double res = (double)sum / (double)num;
        printf("Case %d: average length between pages = %.3f clicks\n" , ++cases , res);
    }



return 0;
}
