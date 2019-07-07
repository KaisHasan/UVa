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

int solve(int n){
    int i;
    int res = 1;
    for( i = 2 ; i * i < n ; ++i){
        if(n%i == 0){
            res += i;
            res += n / i;
        }
    }
    if(i * i == n)
        res += i;
return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    printf("PERFECTION OUTPUT\n");
    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        int res = solve(n);
        if(n == 1)
            res = 0;
        if(res == n){
            printf("%5d  PERFECT\n" , n);
        }
        else if(res > n){
            printf("%5d  ABUNDANT\n" , n);
        }
        else
            printf("%5d  DEFICIENT\n" , n);
    }

    printf("END OF OUTPUT\n");

return 0;
}
