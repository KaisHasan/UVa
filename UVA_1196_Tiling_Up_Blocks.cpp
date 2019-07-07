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

int n;
pi a[MAX];
int dp[MAX];
int res;
void solve(){
    fill(dp , dp + n , 1);
    for(int i = 0 ; i < n ; ++i){
        for(int j = i + 1 ; j < n ; ++j){
            if(a[j].first >= a[i].first && a[j].second >= a[i].second)
                dp[j] = max(dp[j] , 1 + dp[i]);
        }
    }
    res = -inf;
    for(int i = 0 ; i < n ; ++i)
        res = max(res, dp[i]);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        sc(n);
        if(!n){
            printf("*\n");
            break;
        }
        for(int i = 0 ; i < n ; ++i){
            int x , b;
            sc(x);sc(b);
            a[i].first = x;a[i].second = b;
        }
        sort(a , a + n);
        solve();
        printf("%d\n" , res);
    }



return 0;
}
