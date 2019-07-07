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

//n choose k
ll C(int n , int k){
    vi a , b;
    a.clear();
    b.clear();
    int mx = max(k , n - k);
    for(int i = n ; i > mx ; --i)
        a.pb(i);
    int mn = min(k , n - k);
    for(int i = 2 ; i <= mn ; ++i)
        b.pb(i);
    for(int i = 0 ; i < (int)a.size() ; ++i){
        for(int j = 0 ; j < (int)b.size() ; ++j){
            int d = __gcd(a[i] , b[j]);
            a[i] /= d;
            b[j] /= d;
        }
    }
    ll res1 = 1;
    for(auto it : a)
        res1 *= (ll)it;
    ll res2 = 1;
    for(auto it : b)
        res2 *= (ll)it;
    return res1 / res2;
}

double a[MAX];

double B(int n , int r , int i){
    double p = a[i];
    double q = 1 - p;
    double p_to_r = 1;
    for(int i = 0 ; i < r ; ++i)
        p_to_r *= p;
    double q_to_n_r = 1;
    for(int i = 0 ; i < n - r ; ++i)
        q_to_n_r *= q;
    double res = C(n,r) * p_to_r * q_to_n_r;
    return res;
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int cases = 0;
    while(1){
        int n , r;
        sc(n);sc(r);
        if(!n && !r)
            break;
        double sum = 0;
        for(int i = 0 ; i < n ; ++i){
            scd(a[i]);
            sum += a[i];
        }
        for(int i = 0 ; i < n ; ++i){
            a[i] /= sum;
        }
        printf("Case %d:\n" , ++cases);
        double res = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 1 ; j <= r ; ++j){
                res += B(n , j , i);
            }
            printf("%.2f\n" , res);
            res = 0;
        }
    }



return 0;
}
