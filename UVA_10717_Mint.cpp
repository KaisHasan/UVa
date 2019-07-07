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

int len[MAX];
vi av;
void build(int n){
    for(int i = n ; i < MAX ; i += n){
        len[i]++;
        if(len[i] == 4)
            av.pb(i);
    }
}

int bin(int x , int ch){
    int st = 0 , en = av.size() - 1;
    int res = -1;
    if(ch == 1){
        while(st <= en){
            int md = (st + en)>>1;
            if(av[md] <= x){
                res = md;
                st = md + 1;
            }
            else
                en = md - 1;
        }
    }
    else{
        while(st <= en){
            int md = (st + en)>>1;
            if(av[md] < x){
                st = md + 1;
            }
            else{
                res = md;
                en = md - 1;
            }
        }
    }
    return res;
}
int a[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        int n, m;
        sc(n);sc(m);
        if(!n && !m)
            break;
        av.clear();
        mem(len , 0);
        for(int i = 0 ; i < n ; ++i){
            sc(a[i]);
            build(a[i]);
        }
        sort(a , a + n);
        sort(all(av));
        for(int i = 0 ; i < m ; ++i){
            int x;sc(x);
            int pos1 = bin(x , 1);
            int pos2 = bin(x , 2);
            int res1 = (pos1 != -1) ? av[pos1] : 0;
            int res2 = (pos2 != -1) ? av[pos2] : -1;
            if(res2 == -1){
                res2 = 1;
                for(int i = 0 ; i < 4 ; ++i){
                    res2 = (res2 * a[i])/__gcd(res2 , a[i]);
                }
            }
            printf("%d %d\n"  , res1 , res2);
        }
    }



return 0;
}
