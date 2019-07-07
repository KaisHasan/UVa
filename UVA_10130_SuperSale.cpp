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
struct object{
    int p , w;
    object(int a = 0 , int b = 0){
        p = a;
        w = b;
    }
};
int n;
object a[1050];
int dp[1005][40];
int solve(int id , int rem){
    if(id == n)
        return 0;
    int &res = dp[id][rem];
    if(res != -1)
        return res;
    res = 0;
    res = max(res , solve(id + 1 , rem));
    if(rem - a[id].w >= 0)
        res = max(res , solve(id + 1  , rem - a[id].w) + a[id].p);
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
while(t--){
    memset(dp , -1, sizeof(dp));
    sc(n);
    for(int i = 0 ;i < n ; ++i){
        int p , w;
        sc(p);sc(w);
        a[i].p = p;
        a[i].w = w;
    }
    int res = 0;
    int g;
    sc(g);
    for(int i = 0 ; i < g ; ++i){
        int x;
        sc(x);
        res += solve(0 , x);
    }
    printf("%d\n" , res);

}



return 0;
}
