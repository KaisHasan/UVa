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

int n , m;
int a , b;
int f[16050];
int cal(){

    int p = 1;
    for(int i = 1 ; i <= m ; ++i)
        p *= 10;
    f[0] = a % p;
    f[1] = b % p;
    for(int i = 2; i <= n ; ++i){
        f[i] = (f[i-1] % p + f[i-2] % p) % p;
    }
    return f[n];
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        sc(a);sc(b);
        sc(n);sc(m);
        if(m == 1)
            n %= 60;
        else if(m == 2)
            n %= 300;
        else if(m == 3)
            n %= 1500;
        else
            n %= 15000;
        int res = cal();
        printf("%d\n" , res);
    }



return 0;
}
