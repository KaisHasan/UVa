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

int power(int x , int y){
    if(!y)
        return 1;
    int res = power(x , y / 2);
    res *= res;
    if(y & 1)
        res *= x;
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    seive(100000);
    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        if(!is_prime(n)){
            printf("Given number is NOT prime! NO perfect number is available.");
        }
        else{
            int mers = power(2 , n) - 1;
            if(!is_prime(mers)){
                printf("Given number is prime. But, NO perfect number is available.");
            }
            else{
                ll res = (ll)power(2 , n - 1) * (ll)mers;
                printf("Perfect: %lld!" , res);
            }
        }
        blank;
    }



return 0;
}
