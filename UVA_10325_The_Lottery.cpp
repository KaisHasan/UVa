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

vector<ll> v(16);
ll x;
int m;
ll inc_exc(int id = 0 , ll d = 1, ll sign = -1){
    if(id == m){
        if(d == 1)
            return 0;
        return (sign * x)/d;
    }
    return inc_exc(id + 1 , d , sign) + inc_exc(id + 1 ,d * v[id] / __gcd(d , v[id]) , sign * -1);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int n;
while(sc(n) != EOF){
    sc(m);
    x = n;
    for(int i = 0 ; i < m; ++i)
        scl(v[i]);
    int res = n - inc_exc();
    printf("%d\n" , res);

}


return 0;
}
