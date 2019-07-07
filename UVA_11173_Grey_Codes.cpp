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


int main(){
//freopen("input.txt" , "r" , stdin);
//freopen("output.txt" , "w" , stdout);

int t;
sc(t);
while(t--){
    int n , k;
    sc(n);sc(k);
    int cur = k;
    bitset<32> b(0);
    while(n >= 0){
        if((1<<n) > cur){
            --n;
        }
        else if((1<<n) == cur){
            b[n] = 1;
            --n;
        }
        else{
            cur = (1<<(n+1)) - cur - 1;
            b[n] = 1;
            --n;
        }
    }
    printf("%u" , b.to_ulong());
    blank;
}





return 0;
}
