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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

const ll n = 200000;
vector<bool> isprime(n+1,true);
vector<ll> primes;
void seive(){
     isprime[0] = isprime[1] = 0;
     for(int i = 2 ; i < n ; ++i){
        if(isprime[i]){
            primes.pb(i);
            for(int j = i * 2 ; j <= n ; j+=i){
                isprime[j] = 0;
            }
        }
     }
}

ll GenerateDivisors(ll m){
    ll res = 1;
    int pf_id = 0;
    ll pf = primes[pf_id];
    while(pf * pf <= m){
        ll power = 0;
        while(m % pf == 0){
            m /= pf;
            ++power;
        }
        res *= (power + 1);
        pf = primes[++pf_id];
    }
    if(m != 1)
        res *= 2;

return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
    int t = 0;
    seive();
    while(1){
        ll m;
        scl(m);
        if(!m)
            break;
        /*if(t)
            blank;*/
        ++t;
        ll res = GenerateDivisors(m);
        if(res % 2)
            printf("yes\n");
        else
            printf("no\n");
    }



return 0;
}
