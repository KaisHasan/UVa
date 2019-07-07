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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , k;
int a[MAX];
int m(int x){
    while(x < 0)
        x += k;
    return x % k;
}
int dp[100003][103];
int solve(int id , int rem){
    if(id == n){
        if(rem == 0)
            return 1;
        return 0;
    }
    int &res = dp[id][rem];
    if(res != -1)
        return res;
    res = 0;
    res |= solve(id + 1 , m(rem + m(a[id])));
    res |= solve(id + 1 , m(rem + m(-a[id])));
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int t;
    sc(t);
    while(t--){
        mem(dp , -1);
        sc(n);sc(k);
        for(int i = 0 ; i < n ; ++i)
            sc(a[i]);
        int res = solve(0 , 0);
        if(res)
            printf("Divisible");
        else
            printf("Not divisible");
        blank;
    }


return 0;
}
