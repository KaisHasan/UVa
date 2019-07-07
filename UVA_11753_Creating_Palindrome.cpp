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

int n , k;
int a[10004];
int dp[10004][24];

int solve(int i , int rem , int j){
    if(i >= j)
        return 0;
    if(rem == k + 1)
        return inf;
    int &res = dp[i][rem];
//    if(res != -1)
//        return res;
    res = inf;
    if(a[i]==a[j])
        res = min(res , solve(i + 1 , rem , j - 1));
    else{
        res = min(res , solve(i , rem + 1 , j - 1) + 1);
        res = min(res , solve(i + 1 , rem + 1 , j) + 1);
    }
    return res;
}

bool check_pal(){
    for(int i = 0 , j = n -1 ; i < j ; ++i , --j)
        if(a[i] != a[j])
            return false;
    return true;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        sc(n);sc(k);
        for(int i = 0 ; i < n ; ++i)
            sc(a[i]);
        mem(dp , -1);
        printf("Case %d: " , ++cases);
        if(check_pal()){
            printf("Too easy\n");
            continue;
        }
        int res = solve(0 , 0 , n - 1);
        if(res > k)
            printf("Too difficult");
        else
            printf("%d" , res);
        blank;
    }



return 0;
}
