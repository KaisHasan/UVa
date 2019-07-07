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

int cuts[55];
int n;
int dp[55][55];
int solve(int s , int e , int is , int ie){
    if(s > e)
        return 0;
    if(is > ie)
        return 0;
    int &res = dp[is][ie];
    if(res != -1)
        return res;
    res = inf;
    for(int i = is ; i <= ie ; ++i){
        int c = cuts[i];
        res = min(res , solve(s , c , is , i - 1) + solve(c + 1 , e , i + 1 , ie) + (e - s + 1));
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        int l;
        sc(l);
        if(!l)
            break;
        sc(n);
        for(int i = 0 ; i < n ; ++i)
            sc(cuts[i]);
        mem(dp , -1);
        int res = solve(1 , l , 0 , n - 1);
        printf("The minimum cutting is %d.\n" , res);
    }



return 0;
}
