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

int res[MAX];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int l , h , r;
    int mxr = -1;
    while(scanf("%d %d %d" , &l , &h , &r) != EOF){
        for(int i = l ; i < r ; ++i){
            res[i] = max(res[i] , h);
        }
        mxr = max(mxr , r);
    }
//    pla;
//    for(int i = 0 ; i < 31 ; ++i)
//        printf("res[%d] ==   %d\n" , i , res[i]);
//    pla;
    printf("1 %d" , res[1]);
    int i = 1;
    while(i < mxr){
        int cur = res[i];
        while(i < mxr && res[i] == cur)
            ++i;
        printf(" %d %d" , i , res[i]);
    }
    blank;


return 0;
}
