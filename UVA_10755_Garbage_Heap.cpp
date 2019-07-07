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
const ll inf = 1e17+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

ll A , B , C;
ll shit[40][40][40];
ll solve(){
    for(int i = 1 ; i <= A ; ++i){
        for(int j = 1 ;  j <= B ; ++j){
            for(int k = 1 ; k <= C ; ++k){
                shit[i][j][k] += shit[i][j][k-1] + shit[i][j-1][k] - shit[i][j-1][k-1];
            }
        }
    }
    ll mxSum = 0;
    for(int j = 1 ; j <= B ; ++j){
        for(int k = 1 ; k <= C ; ++k){
            for(int j1 = j ; j1 <= B ; ++j1){
                for(int k1 = k ; k1 <= C ; ++k1){
                    ll sum = 0;
                    for(int i = 1 ; i <= A ; ++i){
                        sum += shit[i][j1][k1] - shit[i][j-1][k1] - shit[i][j1][k-1] + shit[i][j-1][k-1];
                        if(sum < 0)
                            sum = 0;
                        mxSum = max(mxSum , sum);
                    }
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
        scl(A);scl(B);scl(C);
        for(int i = 1 ; i <= A ; ++i){
            for(int j = 1 ; j <= B ; ++j){
                for(int k = 1 ; k <= C ; ++k){
                    scl(shit[i][j][k]);
                }
            }
        }
        ll res = solve();
        if(!res){
            res = -inf;
            for(int i = 1 ; i <= A ; ++i){
                for(int j = 1 ; j <= B ; ++j){
                    for(int k = 1 ; k <= C ; ++k){
                        res = max(res , shit[i][j][k]);
                    }
                }
            }
        }
        printf("%lld\n" , res);
        if(t)
            blank;
    }



return 0;
}
