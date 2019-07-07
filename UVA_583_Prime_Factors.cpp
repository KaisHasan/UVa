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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll SIZE;
bitset<20000010> isprime;
vi primes;
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(int i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            for(ll j = (ll)i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
            primes.pb((int)i);
        }
    }
}

bool is_prime(int n){
    if(n < SIZE)
        return isprime[n];
    for(int i = 0 ; i < (int)primes.size() ; ++i)
        if(n % primes[i] == 0)
            return false;
    return true;
}

vll res;
void factorization(int n){
    for(auto p : primes){
        if((ll)p * p > n)
            break;
        while(n % p == 0){
            n /= p;
            res.pb(p);
        }
    }
    if(n > 1)
        res.pb(n);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

seive(150000);
    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        res.clear();
        factorization(abs(n));
        printf("%d = " , n);
        if(n < 0)
            printf("-1");
        else
            printf("%lld" , res[0]);
        for(int i = (n>=0) ; i < (int)res.size() ; ++i)
            printf(" x %lld" , res[i]);
        blank;
    }



return 0;
}
