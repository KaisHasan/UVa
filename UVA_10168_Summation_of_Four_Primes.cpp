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
const int MAX = 1e6+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll SIZE;
bitset<10000010> isprime;
vector<ll> primes;
int pre[MAX * 10];
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    pre[0] = pre[1] = -1;
    int cur = 2;
    for(ll i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            cur = i;
            for(ll j = i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
            primes.pb(i);
        }
        pre[i] = cur;
    }
}

int p[4];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    seive(10000001);
    int n;
    while(sc(n) != EOF){
        if(n <= 6){
            printf("Impossible.\n");
            continue;
        }
        int n1 = n - 6;
        int res = pre[n1];
        if(res == -1){
            printf("Impossible.\n");
            continue;
        }
        p[0] = res;
        if(n < 4){
            printf("Impossible.\n");
            continue;
        }
        n -= res;
        int n2 = n - 4;
        res = pre[n2];
        if(res == -1){
            printf("Impossible.\n");
            continue;
        }
        p[1] = res;
        if(n < 2){
            printf("Impossible.\n");
            continue;
        }
        n -= res;
        int n3 = n - 2;
        res = pre[n3];
        if(res == -1){
            printf("Impossible.\n");
            continue;
        }
        p[2] = res;
        n -= res;
        res = pre[n];
        if(res == -1){
            printf("Impossible.\n");
            continue;
        }
        p[3] = res;
        printf("%d" , p[0]);
        for(int i = 1 ; i < 4 ; ++i){
            printf(" %d" , p[i]);
        }
        blank;
    }



return 0;
}
