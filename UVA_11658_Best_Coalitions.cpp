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

int n , x;
int a[150];
int dp[105][10005];
int solve(int id , int sum){
    if(id == n){
        if(sum > 5000)
            return 0;
        return inf;
    }
    int &res = dp[id][sum];
    if(res != -1)
        return res;
    res = inf;
    if(id != x - 1)
        res = min(res , solve(id + 1 , sum));
    res = min(res , solve(id + 1 , sum + a[id]) + a[id]);
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


while(1){
memset(dp , -1 , sizeof(dp));

    sc(n);sc(x);
    if(!n && !x)
        break;
    double d;
    for(int i = 0 ; i < n ; ++i){
        int r , b;
        scanf("%d.%d" , &r , &b);
        a[i] = r * 100 + b;
    }
    double ans;
    if(a[x-1] > 5000)
        ans = 100.00;
    else{
        int res = solve(0 , 0);
        ans = (1.0 * a[x-1] * 100.0) / res;
    }
    printf("%.2f\n" , ans);
}



return 0;
}
