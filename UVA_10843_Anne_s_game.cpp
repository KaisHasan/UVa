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
#define scl(a) scanf("%I64d",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
//vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const ll MOD = 2000000011;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll power(ll x , ll y){
    if(!y)
        return 1;
    ll res = power(x , y / 2);
    res = (res * res) % MOD;
    if(y & 1)
        res = (res * x) % MOD;
    return res % MOD;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    for(int cases = 1; cases <= t ; ++cases){
        ll n;
        scl(n);
        printf("Case #%d: %lld\n" ,cases , (n == 1)? 1 : power(n , n - 2));
    }



return 0;
}
