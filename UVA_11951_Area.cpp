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

int n , m , k;
ll a[150][150];
ll p , s;
ll mx_l , mx_r , price;
ll mx_w;
//find the biggest area with sum not greater then k
//Area Problem
//solved using 2D kadnes algorithm and two pointers
void solve(){
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(j > 0)
                a[i][j] += a[i][j-1];
        }
    }
    ll sum = 0;
    mx_l = 0;
    mx_r = 0;
    mx_w = 0;
    price = inf;
    for(int j1 = 0 ; j1 < m ; ++j1){
        for(int j2 = j1 ; j2 < m ; ++j2){
            sum = 0;
            ll w = j2 - j1 + 1;
            ll l = 0 , r = 0;
            while(l < n){
                while(r < n && sum + a[r][j2] - ((j1 > 0)? a[r][j1-1] : 0)<= k){
                    sum += a[r][j2] - ((j1 > 0)? a[r][j1-1] : 0);
                    ++r;
                }
                if((r - l)*w > (mx_r - mx_l)*mx_w){
                    mx_l = l;
                    mx_r = r;
                    mx_w = w;
                    price = sum;
                }
                if((r - l)*w == (mx_r - mx_l)*mx_w){
                    if(sum < price){
                        mx_l = l;
                        mx_r = r;
                        mx_w = w;
                        price = sum;
                    }
                }
                sum -= a[l][j2] - ((j1 > 0)? a[l][j1-1] : 0);
                ++l;
            }
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
for(int cases = 1 ;  cases <= t ; ++cases){
    sc(n);sc(m);sc(k);
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            scl(a[i][j]);
        }
    }
    solve();
    printf("Case #%d: %lld %lld\n" , cases , (mx_r - mx_l)*mx_w , price);
}



return 0;
}
