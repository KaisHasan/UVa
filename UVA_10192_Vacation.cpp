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

string s , t;
int n , m;
int dp[200][200];
int solve(int i , int j){
    if(i == n || j == m)
        return 0;
    int &res = dp[i][j];
    if(res != -1)
        return res;
    res = -2;
    if(s[i] == t[j])
        res = max(res , solve(i + 1 , j + 1) + 1);
    else{
        res = max(solve(i , j + 1) , solve(i + 1 , j));
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
    while(1){
        s.clear();
        t.clear();
        mem(dp , -1);
        getline(cin , s);
        if(s[0] == '#')
            break;
        getline(cin , t);
        n = s.size();
        m = t.size();
        int res = solve(0 , 0);
        printf("Case #%d: you can visit at most %d cities.\n" ,++cases , res);
    }



return 0;
}
