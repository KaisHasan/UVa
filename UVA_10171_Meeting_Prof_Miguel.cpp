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

int n;
vi nodes;
int adj[100][100][2];
int exist[100];

void floyd(int id){
    for(int k = 0 ; k < n ; ++k){
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                int u = nodes[i];
                int v = nodes[j];
                int _k = nodes[k];
                adj[u][v][id] = min(adj[u][v][id] , adj[u][_k][id] + adj[_k][v][id]);
            }
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        mem(exist , 0);
        nodes.clear();
        int m ;
        sc(m);
        if(!m)
            break;
        for(int k = 0 ; k < 2 ; ++k){
            for(int i = 0 ; i < 100 ; ++i){
                for(int j = 0 ; j < 100 ; ++j){
                    adj[i][j][k] = inf;
                }
            }
        }
        while(m--){
            char c;cin>>c;
            int id;
            if(c == 'Y')
                id = 0;
            else
                id = 1;
            char d;cin>>d;
            char c1 , c2;
            cin>>c1;
            cin>>c2;
            int u = c1 - 'A';
            int v = c2 - 'A';
            int w;cin>>w;
            if(!exist[u]){
                exist[u] = 1;
                nodes.pb(u);
            }
            if(!exist[v]){
                exist[v] = 1;
                nodes.pb(v);
            }
            if(u == v)
                w = 0;
            adj[u][v][id] = min(adj[u][v][id],w);
            if(d == 'B')
                adj[v][u][id] = min(adj[v][u][id],w);
        }
        char f1 ,f2;
        cin>>f1>>f2;
        int me = f1 - 'A';
        int miguel = f2 - 'A';
        n = nodes.size();
        floyd(0);
        floyd(1);
        int mn = inf;
        vi res;
        for(int i = 0 ; i < n ; ++i){
            int k = nodes[i];
            if(k == me || k == miguel)
                continue;
            if(adj[me][k][0] + adj[miguel][k][1] < mn){
                res.clear();
                mn = adj[me][k][0] + adj[miguel][k][1];
                res.pb(k);
            }
            else if(adj[me][k][0] + adj[miguel][k][1] == mn && mn != inf){
                res.pb(k);
            }
        }
        if(adj[me][miguel][0] < mn){
            mn = adj[me][miguel][0];
            res.clear();
            res.pb(miguel);
        }
        else if(adj[me][miguel][0] == mn && mn != inf){
            if(find(all(res) , miguel) == res.end())
                res.pb(miguel);
        }
        if(adj[miguel][me][1] < mn){
            mn = adj[miguel][me][1];
            res.clear();
            res.pb(me);
        }
        else if(adj[miguel][me][1] == mn && mn != inf){
            if(find(all(res) , me) == res.end())
                res.pb(me);
        }
        if(me == miguel){
            if(mn != 0){
                mn = 0;
                res.clear();
            }
            if(find(all(res) , me) == res.end())
                res.pb(me);
        }
        if(res.size() > 0){
            printf("%d" , mn);
            sort(all(res));
            for(int i = 0 ; i < (int)res.size() ; ++i)
                printf(" %c" , char(res[i] + 'A'));
            blank;
        }
        else
            printf("You will never meet.\n");
    }



return 0;
}
