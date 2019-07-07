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

ll n , a , b;
ll f(ll x){
    ll res = a % n;
    res = (res * (x%n))%n;
    res = (res * (x%n))%n;
    res = (res + (b%n))%n;
    return res;
}

pair<ll,ll> Fcycle(ll x0){
    // 1st part: finding k*mu, hare's speed is 2x tortoise's
    ll tortoise = f(x0), hare = f(f(x0));
    while(tortoise != hare){
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    //2Nd part: finding mu, hare and tortoise move at the same speed
    ll mu = 0;
    hare = x0;
    while(tortoise  != hare){
        tortoise = f(tortoise);
        hare = f(hare);
        ++mu;
    }
    //3d part: finding lambda, hare moves tortoise stays
    ll lambda = 1;
    hare = f(tortoise);
    while(tortoise != hare){
        hare = f(hare);
        ++lambda;
    }
    return MP(mu , lambda);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        scl(n);
        if(!n)
            break;
        scl(a);scl(b);
        pi res = Fcycle(0);
//        printf("mu == %d , lambda == %d\n" , res.first , res.second);
        printf("%lld\n" , n - res.second);
    }



return 0;
}
