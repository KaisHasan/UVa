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
//vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll a[101], b[101];
void fact1(ll st, int n){
    int id = 0;
    for(int i = st ; i > n ; --i){
        a[id++] = i;
    }
}
void fact2(ll st, int n){
    int id = 0;
    for(int i = st ; i > n ; --i){
        b[id++] = i;
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

while(1){
    int n , m;
    sc(n);sc(m);
    if(!n && !m)
        break;
    mem(a , 0);
    mem(b , 0);
    fact1(n , max(n - m , m));
    fact2(min(m , n - m) , 0);
    for(int i = 0 ; i < 101 ; ++i){
        if(a[i] != 0){
            for(int j = 0 ; j < 101 ; ++j){
                if(a[j] != 0){
                    int d = __gcd(a[i] , b[j]);
                    a[i] /= d;
                    b[j] /= d;
                }
            }
        }
    }
    ll res1 = 1;
    for(int i = 0 ; i<101 ; ++i){
        if(a[i] != 0)
            res1 *= a[i];
    }
    ll res2 = 1;
    for(int i = 0 ; i<101 ; ++i){
        if(b[i] != 0)
            res2 *= b[i];
    }
    ll res = res1 / res2;
    printf("%d things taken %d at a time is %lld exactly.\n" , n , m , res);

}



return 0;
}
