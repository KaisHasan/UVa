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
const int MAX = 10000;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n;
int a[] = {1 , 5 , 10 , 25 , 50};
int dp[MAX][5];
int solve(int rem , int id){
    if(id == 5){
        if(rem == 0)
            return 1;
        return 0;
    }
    int &res = dp[rem][id];
    if(res != -1)
        return res;
    res = 0;
    res += solve(rem , id + 1);
    if(rem - a[id] >= 0)
        res += solve(rem - a[id] , id);
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
memset(dp , -1 , sizeof(dp));

while(sc(n) != EOF){
    printf("%d\n" , solve(n , 0));
}



return 0;
}
