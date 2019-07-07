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

int a[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
    int n;
    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    int q;
    sc(q);
    for(int i = 0 ; i < q ; ++i){
        int t;
        sc(t);
        int lower = lower_bound(a , a + n , t) - a;
        --lower;
        int taller = upper_bound(a , a + n , t) - a;
        if(lower < 0)
            printf("X ");
        else
            printf("%d " , a[lower]);
        if(taller == n)
            printf("X\n");
        else
            printf("%d\n" , a[taller]);
    }




return 0;
}
