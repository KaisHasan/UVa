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

int a[6];
bool exist;
void solve(int sum , int cur){
    if(cur == 31){
        if(sum == 23)
            exist = true;
        return;
    }
    for(int i = 0 ;i < 5 ; ++i){
        if((1<<i)&cur)
            continue;
        solve(sum * a[i] , cur | (1<<i));
        solve(sum + a[i] , cur | (1<<i));
        solve(sum - a[i] , cur | (1<<i));
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

while(1){
    int valid = false;
    for(int i= 0 ; i < 5 ; ++i){
        sc(a[i]);
        if(a[i])
            valid = true;
    }
    if(!valid)
        break;
    exist = false;
    for(int i = 0 ; i < 5 ; ++i)
        solve(a[i] , 1<<i);
    if(!exist)
        printf("Impossible\n");
    else
        printf("Possible\n");
}



return 0;
}
