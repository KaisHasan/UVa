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

vi adj[200];
vi bestBlack;
vi curBlack;
int Black[200];
int n;
bool valid(int x){
    for(auto v : adj[x])
        if(x == v || Black[v])
            return false;
    return true;
}

void backTrack(int cur){
    if(bestBlack.size() < curBlack.size())
        bestBlack = curBlack;
    if(cur == n)
        return;
    int max_possible = n - cur;
    if((int)curBlack.size() + max_possible <= (int)bestBlack.size())
        return;
    for(int i = cur ; i < n ; ++i){
        if(valid(i)){
            Black[i] = 1;
            curBlack.pb(i);

            backTrack(i + 1);

            Black[i] = 0;
            curBlack.pop_back();
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int m;
    sc(m);
    while(m--){
        int k;
        sc(n);sc(k);
        while(k--){
            int u , v;
            sc(u);sc(v);
            --u;--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        curBlack.clear();
        bestBlack.clear();
        mem(Black , 0);
        backTrack(0);
        printf("%d\n" , (int)bestBlack.size());
        if((int)bestBlack.size() != 0)
            printf("%d" , bestBlack[0] + 1);
        for(int i = 1 ; i < (int)bestBlack.size() ; ++i){
            printf(" %d" , bestBlack[i] + 1);
        }
        blank;
        for(int i = 0 ; i < n ; ++i)
            adj[i].clear();
    }



return 0;
}
