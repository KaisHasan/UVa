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
const int MAX = 500;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

bool adj[MAX][MAX];
map<string ,int> trans;
map<int , string> decode;
vi a[MAX];
int exist[MAX][MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int cases = 0;
    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        int cur = 0;
        trans.clear();
        decode.clear();
        mem(adj , 0);
        mem(exist , 0);
        for(int i = 0 ; i < n ; ++i){
            int num;
            sc(num);
            while(num--){
                string s;
                cin>>s;
                if(trans.find(s) == trans.end()){
                    trans[s] = cur++;
                    decode[cur-1] = s;
                }
                int u = trans[s];
                a[i].pb(u);
            }
        }
        for(int i = 0 ; i < n; ++i){
            for(int j = 0 ; j < (int)a[i].size() - 1; ++j){
                int u = a[i][j];
                int v = a[i][j+1];
                adj[u][v] = 1;
            }
        }
        int m;
        sc(m);
        while(m--){
            string s , t;
            cin>>s>>t;
            if(trans.find(s) == trans.end()){
                trans[s] = cur++;
                decode[cur-1] = s;
            }
            if(trans.find(t) == trans.end()){
                trans[t] = cur++;
                decode[cur-1] = t;
            }
            int u = trans[s];
            int v = trans[t];
            adj[u][v] = 1;
        }
        for(int t = 0 ; t < cur ; ++t){
            for(int i = 0 ; i < cur ; ++i){
                for(int j =0 ; j < cur; ++j){
                    adj[i][j] |= (adj[i][t] & adj[t][j]);
                }
            }
        }
        int cnt = 0;
        vpi res;
        res.clear();
        for(int i = 0 ; i < cur ; ++i){
            for(int j = 0 ; j < cur ; ++j){
                if(exist[j][i] || exist[i][j] || adj[i][j] || adj[j][i] || i == j)
                    continue;
                ++cnt;
                res.pb(MP(i,j));
                exist[i][j] = 1;
            }
        }
        printf("Case %d, " , ++cases);
        if(cnt){
            printf("%d concurrent events:\n" , cnt);
            for(int i = 0 ; i < min(2 , (int)res.size()) ; ++i){
                string s = decode[res[i].first];
                string t = decode[res[i].second];
                cout<<"("<<s<<','<<t<<") ";
            }
            blank;
        }
        else
            printf("no concurrent events.\n");

        for(int i = 0 ; i < n ; ++i)
            a[i].clear();

    }



return 0;
}
