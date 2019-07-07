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

string s;
int n;
ll dp[123][123];

ll solve(int l , int r){
    if(l >= r)
        return 1;
    ll &res = dp[l][r];
    if(res != -1)
        return res;
    res = 0;
    if(s[l] == s[r])
        res += solve(l + 1 , r - 1);
    res += solve(l + 1 , r);
    res += solve(l , r - 1);
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        s.clear();
        cin>>s;
        n = s.size();
        mem(dp,-1);
        ll res = solve(0,n-1);
        printf("%lld\n" , res);
    }



return 0;
}
