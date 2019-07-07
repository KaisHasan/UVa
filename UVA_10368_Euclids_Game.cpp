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

map<pair<ll , ll> , bool> dp;

bool isWinning(ll x , ll y){
    if(x == 0 || y == 0)
        return false;
    if(x >= y){
        int mxM = x / y;
        mxM *= y;
        for(int i = mxM ; i >= y ; i -= y)
            if(!isWinning(x - i , y))
                return true;
    }
    else{
        int mxM = y / x;
        mxM *= x;
        for(int i = mxM ; i >= x ; i -= x){
            if(!isWinning(x , y - i))
                return true;
        }
    }
    return false;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        ll x , y;
        scl(x);scl(y);
        if(!x && !y)
            break;
        if(isWinning(x , y))
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }



return 0;
}
