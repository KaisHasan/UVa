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
int old_n;
int a[200][200];
int solve(){
    for(int i = 0 ; i < n ; ++i){
        for(int j = 1 ; j < n ; ++j){
            a[i][j] += a[i][j-1];
        }
    }

    int mxSum = 0;
    int sum = 0;
    for(int j1 = 0 ; j1 < n ; ++j1){
        for(int j2 = j1 ; j2 < n ; ++j2){
            if(j2 - j1 + 1 > old_n)
                break;

            for(int i1 = 0 ; i1 < n ; ++i1){
                sum = 0;
                int l = 0;
                for(int i = i1 ; i < n ; ++i){
                    sum += a[i][j2] - ((j1 > 0)? a[i][j1-1] : 0);
                    ++l;
                    if(sum <= 0 || l > old_n){
                        if(l > old_n && a[i][j2] - ((j1 > 0)? a[i][j1-1] : 0) > 0){
                            sum = a[i][j2] - ((j1 > 0)? a[i][j1-1] : 0);
                            l = 1;
                        }
                        else{
                            sum = 0;
                            l = 0;
                        }
                    }
                    if(l == old_n && a[i][j2] - ((j1 > 0)? a[i][j1-1] : 0) > 0){
                        mxSum = max(mxSum , sum);
                        sum = a[i][j2] - ((j1 > 0)? a[i][j1-1] : 0);
                        l = 1;
                    }

                    mxSum = max(mxSum , sum);
                }
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
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            sc(a[i][j]);
        }
    }
    for(int i = 0 ; i < 2 * n ; ++i){
        for(int j = 0 ;j < 2 * n ; ++j){
            a[i][j] = a[i%n][j%n];
        }
    }
    int mx = -inf;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            mx = max(mx , a[i][j]);
        }
    }
    old_n = n;
    n *= 2;

    int res = solve();
    if(!res){
        res  =mx;
    }
    printf("%d\n" , res);
}



return 0;
}
