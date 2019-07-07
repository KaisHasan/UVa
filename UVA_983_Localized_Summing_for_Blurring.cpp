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
const int MAX = 2005;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n , m;
int a[MAX][MAX];
ll res[MAX][MAX];

void cs(){
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            a[i][j] += a[i][j-1];
            a[i][j] += a[i-1][j];
            a[i][j] -= a[i-1][j-1];
        }
    }
}

void solve(){
    for(int i = 1 ;i + m - 1 <= n ;++i){
        for(int j = 1 ; j + m - 1 <= n ; ++j){
            res[i][j] = a[i + m - 1][j + m - 1];
            res[i][j] -= a[i-1][j + m - 1];
            res[i][j] -= a[i+ m - 1][j-1];
            res[i][j] += a[i-1][j-1];
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int f = false;
while(scanf("%d %d", &n, &m) == 2){
    if(f)
        blank;
    f = true;
    for(int i = n; i > 0 ; i--){
        for(int j = 1 ; j <= n ; ++j){
            sc(a[i][j]);
        }
    }
    cs();
    solve();
    ll sum = 0;
    for(int i = n - m + 1; i > 0 ;--i){
        for(int j = 1 ; j + m - 1 <= n ; ++j){
            printf("%lld\n" , res[i][j]);
            sum += res[i][j];
        }
    }
    printf("%lld\n" , sum);

}



return 0;
}
