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
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n , m;
int x , y;
int k;
pi loc[15];
int dist[30][30];
int dp[15][2140];
int solve(int id , int lst){
    if(lst == (1<<(k+1))-1){
        return dist[id][0];
    }
    int &res = dp[id][lst];
    if(res != -1)
        return res;
    res = inf;
    for(int i = 0 ; i <= k ; ++i){
        if(i == id || lst & (1<<i))
            continue;
        res = min(res , solve(i , lst | (1<<i)) + dist[id][i] );
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int t;
sc(t);
while(t--){
    memset(dp , -1 , sizeof(dp));
    sc(n);sc(m);
    sc(x);sc(y);
    sc(k);
    for(int i = 1 ;i <= k ; ++i){
        int u , v;
        sc(u);sc(v);
        loc[i].first = u;
        loc[i].second = v;
    }
    loc[0].first = x;
    loc[0].second = y;
    for(int i = 0 ;i <= k ; ++i){
        for(int j = 0; j <= k ; ++j)
            dist[i][j] = abs(loc[i].first - loc[j].first) + abs(loc[i].second - loc[j].second);
    }
    int res = solve(0 , 1);
    printf("The shortest path has length %d\n" , res);

}



return 0;
}
