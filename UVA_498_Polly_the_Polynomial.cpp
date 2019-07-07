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

vi c(MAX);
ll power(ll x , ll y){
    if(!y)
        return 1;
    ll res = power(x , y / 2);
    res *= res;
    if(y & 1)
        res *= x;
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
    while(1){
        c.clear();
        char t = '*';
        int n = 0;
        do{
            if(scanf("%d%c" , &c[n] , &t) != 2)
                break;
            ++n;
        }while(t != '\n');
        if(!n)
            break;
        string s;
        getline(cin ,s);
        istringstream iss(s);
        int x;
        int cnt = 0;
        while(iss >> x){
            ll sum = 0;
            for(int i = 0 ; i < n ; ++i){
                sum += (c[i] * power(x , n - i - 1));
            }
            if(cnt)
                printf(" ");
            ++cnt;
            printf("%lld" , sum);
        }
        blank;
    }



return 0;
}
