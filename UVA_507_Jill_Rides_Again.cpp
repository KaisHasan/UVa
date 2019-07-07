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
int a[MAX];
int st , en;

void solve(){
    int sum = 0;
    en = -1;
    st = -1;
    int _st = 0;
    int len = 0;
    int mxSum = 0;
    for(int i = 0 ; i < n - 1; ++i){
        if(sum + a[i] >= 0){
            sum += a[i];
            ++len;
            if(sum > mxSum){
                mxSum = sum;
                st = _st;
                en = _st + len;
            }
            else if(sum == mxSum){
                if(len > en - st){
                    mxSum = sum;
                    st = _st;
                    en = _st + len;
                }
            }
        }
        else{
            sum = 0;
            len = 0;
            _st = i + 1;
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int t;
sc(t);
    for(int r = 1 ; r <= t ; ++r){
        sc(n);
        for(int i = 0 ; i < n - 1; ++i)
            sc(a[i]);
        solve();
        if(st == -1){
            printf("Route %d has no nice parts" , r);
        }
        else{
            if(en == -1){
                en = n;
            }
            printf("The nicest part of route %d is between stops %d and %d" , r , st + 1 , en + 1);
        }
            blank;
    }




return 0;
}
