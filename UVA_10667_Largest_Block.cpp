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

int n , a[150][150];
int solve(){
    for(int i = 0 ; i < n ; ++i){
        for(int j = 1 ; j < n ; ++j){
            a[i][j] +=  a[i][j-1];
        }
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 1 ; j < n ; ++j){
            a[i][j] +=  a[i][j-1];
        }
    }
    int mxSum = 0;
    int sum = 0;
    for(int j1 = 0 ; j1 < n ; ++j1){
        for(int j2 = j1 ; j2 < n ; ++j2){
            sum = 0;
            for(int i = 0 ; i < n ; ++i){
                int temp = a[i][j2] - ((j1 > 0)? a[i][j1-1] : 0);
                if(temp != 0)
                    sum = 0;
                else
                    sum += j2 - j1 + 1;
                mxSum = max(mxSum , sum);
            }
        }
    }
    return mxSum;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
while(t--){
    memset(a , 0 , sizeof(a));
    sc(n);
    int m;
    sc(m);
    while(m--){
        int i1 , j1 , i2 , j2;
        sc(i1);sc(j1);sc(i2);sc(j2);
        --i1;--j1;--i2;--j2;
        for(int i = i1 ; i <= i2 ; ++i){
            a[i][j1] += 1;
            a[i][j2+1] -= 1;
        }
    }
    int res = solve();
    printf("%d\n" , res);
}



return 0;
}
