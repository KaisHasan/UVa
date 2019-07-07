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
const int MAX = 1e4+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int a[] = { 2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1 };
ll dp[MAX];
ll solve(ll rem){
    for(int i =0;i<rem+1;i++)
        dp[i] =0;
    dp[0] = 1;
    for(int i = 0 ; i < 11 ; ++i){
        for(int j = a[i] ; j < rem + 1; ++j){
            dp[j] += dp[j - a[i]];
        }
    }
    return dp[rem];
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
while(1){
    double k;
    scd(k);
    if(k - 0 < eps)
        break;
    ll n = trunc(20.00 * k);
    printf("%6.2f%17llu\n" , k , solve(n));
}




return 0;
}
