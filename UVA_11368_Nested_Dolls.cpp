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
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
#define all(x) x.begin(),x.end()
const int MAX = 21000;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n;
pi a[MAX];

bool cmp(pi a , pi b){
    if(a.first > b.first)
        return 1;
    else if(a.first < b.first)
        return 0;
    else
        return a.second < b.second;
}

//how to find minimum number of LISs in the same time
//nested dolls Problem

int solve(){
    vi v ;
    v.push_back(inf);
    int ans = 0;
    for(int i = 0 ; i < n ; ++i) {
        int now = a[i].second;
        int Idx = lower_bound(all(v),now+1)-v.begin();
        if( Idx == v.size()-1) {
            ans++;
            v.push_back(inf);
        }
        v[Idx] = now;
    }
    return ans;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
while(t--){
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        int u , v;
        sc(u);sc(v);
        a[i].first = u;a[i].second = v;
    }
    sort(a , a + n , cmp);
    int res = solve();
    printf("%d\n" , res);
}



return 0;
}
