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
pi a[1005];
int dp[1005][3005];
int solve(int id , int rem){
    if(id == n){
        return 0;
    }
    int &res = dp[id][rem];
    if(res != -1)
        return res;
    res = max(res , solve(id + 1, rem));
    if(rem - a[id].first >= 0)
        res = max(res , solve(id + 1 , min(rem - a[id].first , a[id].second)) + 1);
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


while(1){
    sc(n);
    if(!n)
        break;
    for(int i = 0 ; i < n ; ++i){
        int x , y;
        sc(x);sc(y);
        a[i].first = x;
        a[i].second = y;
    }
    memset(dp , -1, sizeof(dp));
    int res = -1;
    for(int i = 0 ; i < n ; ++i){
        res = max(res , solve(i + 1 , a[i].second) + 1);
    }
    printf("%d\n" , res);
}



return 0;
}
