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

bool isSquare(int n){
    return (fabs(sqrt(n) - floor(sqrt(n))) < eps);
}

ll res[55];
int col[55];
ll solve(int n){
    if(res[n] != -1)
        return res[n];
    ll &ans = res[n];
    ans = 0;
    mem(col , -1);
    for(int i = 1 ; ; ++i , ++ans){
        bool test = false;
        for(int j = 0 ; j < n ; ++j){
            if(col[j] == -1 || isSquare(i + col[j])){
                test = true;
                col[j] = i;
                break;
            }
        }
        if(!test)
            break;
    }
    return ans;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    mem(res, -1);
    while(t--){
        int n;
        sc(n);
        ll res = solve(n);
        printf("%lld\n" , res);
    }



return 0;
}
