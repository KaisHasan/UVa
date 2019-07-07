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
int a[200][200];
int solve(){
    for(int i = 0 ; i< n; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(j > 0)
                a[i][j] += a[i][j-1];
        }
    }
    int  mxSum = -inf;

    for(int j = 0 ; j < n ; ++j){
        for(int k = j ; k < n ; ++k){
            int sum = 0;
            for(int i = 0 ; i < n ; ++i){
                if(j > 0)
                    sum += a[i][k] - a[i][j-1];
                else
                    sum += a[i][k];
                if(sum < 0)
                    sum = 0;
                mxSum = max(mxSum , sum);
            }
        }
    }
    return mxSum;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
sc(n);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n; ++j)
            sc(a[i][j]);

    int res = solve();
    if(res)
        printf("%d" , res);
    else{
        int mx = -10000;
        for(int i = 0 ; i < n ; ++i){
            for(int j  =0 ; j < n ; ++j){
                mx = max(mx , a[i][j]);
            }
        }
        printf("%d" , mx);
    }
    blank;



return 0;
}
