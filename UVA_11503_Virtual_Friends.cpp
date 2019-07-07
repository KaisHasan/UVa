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

int rnk[MAX];
int par[MAX];
int cmp[MAX];

void initi(int n){
    for(int i = 1 ; i <= n ; ++i){
        par[i] = i;
        cmp[i] = 1;
    }
    mem(rnk , 1);
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}

bool _merge(int u , int v){
    int paru = parent(u) , parv = parent(v);
    if(paru == parv)
        return 0;
    if(rnk[paru] < rnk[parv]){
        par[paru] = parv;
        cmp[parv] += cmp[paru];
        return 1;
    }
    else if(rnk[paru] > rnk[parv])
    {
        par[parv] = paru;
        cmp[paru] += cmp[parv];
        return 1;
    }
    else{
        par[parv] = paru;
        cmp[paru] += cmp[parv];
        rnk[paru]++;
        return 1;
    }
}

map<string , int> trans;


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        initi(3 * n);
        int node = 1;
        for(int i = 0 ; i < n ; ++i){
            string s , t;
            cin>>s>>t;
            if(trans.find(s) == trans.end())
                trans[s] = node++;
            if(trans.find(t) == trans.end())
                trans[t] = node++;
            int u = trans[s];
            int v = trans[t];
            bool res = _merge(u , v);
            printf("%d\n" , cmp[parent(u)]);
        }

        trans.clear();
    }



return 0;
}
