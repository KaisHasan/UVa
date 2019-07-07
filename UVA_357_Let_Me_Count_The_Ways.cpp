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

int a[] = {1 , 5 , 10 , 25 , 50};
ll dp[5][30001];
ll solve(int id , int rem){
    if(id == 5){
        if(rem == 0)
            return 1;
        return 0;
    }
    ll &res = dp[id][rem];
    if(res != -1)
        return res;
    res = 0;
    res += solve(id + 1, rem);
    if(rem - a[id] >= 0)
        res += solve(id , rem - a[id]);
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int n;
memset(dp , -1 , sizeof(dp));
    while(sc(n) != EOF){
        ll res = solve(0 , n);
        if(res == 1)
            printf("There is only 1 way to produce %d cents change.\n" , n);
        else
            printf("There are %lld ways to produce %d cents change.\n" , res , n);
    }



return 0;
}
