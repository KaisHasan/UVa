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
//vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll omega(ll n){
    return (n * (n - 1)) / 2;
}
int a[55];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        for(int i = 0 ; i < n ; ++i)
            sc(a[i]);
        int cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                if(__gcd(a[i] , a[j]) == 1)
                    ++cnt;
            }
        }
        if(cnt != 0){
            double res = (6.0 * omega(n)) / (1.0*cnt);
            res = sqrt(res);
            printf("%.6f\n" , res);
        }
        else{
            printf("No estimate for this data set.\n");
        }
    }



return 0;
}
