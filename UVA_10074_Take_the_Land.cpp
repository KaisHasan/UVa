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

int n , m;
int a[150][150];
int mx_w , mx_l;
void solve(){
    for(int i = 0 ; i < n ; ++i){
        for(int j =1 ; j < m ; ++j){
            a[i][j] += a[i][j-1];
        }
    }

    mx_w = 0 , mx_l = 0;
    int w = 0 , l = 0;
    for(int j1 = 0 ; j1 < m; ++j1){
        for(int j2 = j1 ; j2 < m ; ++j2){
            w = j2 - j1 + 1;
            l = 0;
            for(int i = 0 ; i < n ; ++i){
                int sum = a[i][j2] - ((j1 > 0)? a[i][j1-1] : 0);
                if(sum > 0){
                    l = 0;
                }
                else{
                    ++l;
                }
                if(w * l > mx_w * mx_l){
                    mx_w = w;
                    mx_l = l;
                }
            }
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        sc(n);sc(m);
        if(!m && !n)
            break;
        for(int i = 0 ; i < n; ++i){
            for(int j = 0 ; j < m ; ++j){
                sc(a[i][j]);
            }
        }
        solve();
        printf("%d\n" , mx_w * mx_l);
    }



return 0;
}
