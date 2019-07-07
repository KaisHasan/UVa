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
const int MAX = 140007;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

bool Prime[65001] = {};
void sieve() {
	int i, j;
	for(i = 2; i < 65000; i++) {
		if(Prime[i] == 0) {
			for(j = 2; i*j < 65000; j++)
				Prime[i*j] = 1;
		}
	}
}
long long mod(long long x, long long y, long long m) {
	if(y == 0)
        return 1;
    ll res = mod(x , y>>1 , m);
    res *= res;
    res %= m;
    if(y & 1)
        res = (res * x)%m;
    return res;
}
int Check(int n) {
	int i;
	for(i = 2; i <= n-1; i++) {
		if(mod(i, n, n) != i)
			return 0;
	}
	return 1;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
sieve();
while(1){
    int n;
    sc(n);
    if(!n)
        break;
    if(Prime[n] && Check(n))
        printf("The number %d is a Carmichael number.\n" , n);
    else
        printf("%d is normal.\n" , n);
}



return 0;
}
