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

ll SIZE;
bitset<20000010> isprime;
vi primes;
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(ll i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            for(ll j = i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
            primes.pb((int)i);
        }
    }
}

vector<int> twins;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    seive(20000000);
    for(int i = 0 ; i < primes.size() ; ++i){
        if(primes[i+1] - primes[i] == 2)
            twins.pb(i);
    }
    int n;
    while(sc(n) != EOF){
        int i = twins[n-1];
        int res = primes[i];
        printf("(%d, %d)\n" , res , res + 2);
    }



return 0;
}
