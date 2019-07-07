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
//   coin  number
ll dp[305][305];
vector<int> parse(string &s)
{
    s += ' ';
    int n = 0;
    vector<int> ret;
    for(char c : s)
        if(c == ' ') ret.push_back(n), n = 0;
        else n = 10*n + c - '0';
    return ret;
}

ll query(int n, int l, int r)
{
    if(n == 0) return l == 0 ? 1 : 0;
    l = max(l,1), r = min(r,300);
    return dp[n][r] - dp[n][l-1];
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

memset(dp , 0 , sizeof(dp));

dp[0][0] = 1;
for(int coin = 1 ; coin < 301 ; ++coin){
    for(int i = coin ; i < 301 ; ++i){
        for(int j = 1 ; j < 301 ; ++j){
            dp[i][j] += dp[i-coin][j-1];
        }
    }
}
for(int i = 1 ;i < 301 ; ++i)
    for(int j = 1 ; j < 301 ; ++j)
        dp[i][j] += dp[i][j-1];
while(1){
    string line;
    getline(cin, line);
    if(line.size() < 1) return 0;
    vector<int> v = parse(line);
    if(v.size() == 1)
        printf("%lld\n" , query(v[0], 0, 300));
    if(v.size() == 2)
        printf("%lld\n" , query(v[0], 0, v[1]));
    if(v.size() == 3)
        printf("%lld\n" ,query(v[0], v[1], v[2]) );
}



return 0;
}
