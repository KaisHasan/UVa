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
int tot;
int a[100];
int dp[100][250];
int solve(int id , int sum){
    if(id == n){
        if(sum == tot - sum)
            return 1;
        return 0;
    }
    int &res = dp[id][sum];
    if(res != -1)
        return res;
    res = 0;
    res |= solve(id + 1, sum);
    res |= solve(id + 1 , sum + a[id]);
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int m;
sc(m);
while(m--){
    memset(dp , -1 , sizeof(dp));
    n = 0;
    tot = 0;
    char c;
    do{
        scanf("%d%c" , &a[n++] , &c);
        tot += a[n-1];
    }while(c != '\n');
    if(solve(0 , 0))
        printf("YES\n");
    else
        printf("NO\n");
}



return 0;
}
