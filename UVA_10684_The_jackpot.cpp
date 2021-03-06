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


int n;
int a[MAX];
int solve(){
    int sum = 0;
    int mxSum = 0;
    for(int i = 0 ;  i < n ; ++i){
        if(sum + a[i] < 0){
            sum = 0;
        }
        else{
            sum += a[i];
        }
        mxSum = max(mxSum , sum);
    }
    return mxSum;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
    while(1){
        sc(n);
        if(!n)
            break;
        for(int i = 0 ; i< n; ++i)
            sc(a[i]);
        int res = solve();
        if(res)
            printf("The maximum winning streak is %d.\n" , res);
        else
            printf("Losing streak.\n");
    }




return 0;
}
