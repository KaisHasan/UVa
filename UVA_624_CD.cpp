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
int tot;
int res_n;
int res_s;

void solve(int id  , int sum , int lst){
    if(id == n){
        if(sum > res_s){
            res_s = sum;
            res_n = lst;
        }
        return;
    }
    if(sum + a[id] <= tot)
        solve(id + 1 , sum + a[id] ,  lst | (1<<id));
    solve(id + 1 , sum ,  lst);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(sc(tot) != EOF){
        sc(n);
        for(int i = 0 ; i < n ; ++i)
            sc(a[i]);
        res_s = 0;
        res_n = 0;
        solve(0 , 0 , 0);
        for(int i = 0 ; i < 22; ++i){
            if((1<<i) & res_n)
                printf("%d " , a[i]);
        }
        printf("sum:%d\n" , res_s);
    }



return 0;
}
