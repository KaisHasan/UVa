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

struct node{
    int w , f , lift;
    node(int _w , int _f , int _lift){
        w = _w;
        f = _f;
        lift = _lift;
    }
    node(const node& temp){
        w = temp.w;
        f = temp.f;
        lift = temp.lift;
    }
    friend bool operator>(const node a , const node b){
        return a.w > b.w;
    }
};

vpi adj[MAX][6];
ll dist[MAX][6];
int t[6];
int a[MAX];
int test[6];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    while(sc(n) != EOF){
        int k;
        sc(k);
        for(int i = 0 ; i < n ; ++i){
            sc(t[i]);
        }
        mem(test , 0);
        for(int i = 0 ; i < n ; ++i){
            char c;
            int x;
            int m = 0;
            do{
                scanf("%d%c" , &x , &c);
                a[m++] = x;
            }while(c != '\n');
            sort(a , a + m);
            for(int j = 0 ; j < m - 1; ++j){
                if(a[j] == 0)
                    test[i] = 1;
                int u = a[j];
                int v = a[j+1];
                int w = (a[j+1] - a[j]) * t[i];
                adj[u][i].pb(MP(v,w));
                adj[v][i].pb(MP(u,w));
            }
        }
        for(int i = 0 ; i < MAX ; ++i)
            for(int j = 0 ; j < 6 ; ++j)
                dist[i][j] = inf;
        priority_queue<node , vector<node> , greater<node> > pq;
        for(int i = 0 ; i < 6 ; ++i){
            if(test[i]){
                pq.push(node(0 , 0 , i));
                dist[0][i] = 0;
            }
        }
        while(!pq.empty()){
            node u = pq.top();
//            printf("weight == %d  , floor ==  %d  , lift  ==  %d\n" , u.w , u.f , u.lift);
            pq.pop();
            if(u.w <= dist[u.f][u.lift]){
                for(auto v : adj[u.f][u.lift]){
                    if(dist[u.f][u.lift] + v.second < dist[v.first][u.lift]){
                        dist[v.first][u.lift] = dist[u.f][u.lift] + v.second;
                        pq.push(node(dist[v.first][u.lift] , v.first , u.lift));
                    }
                }
            }
            for(int i = 0 ; i < n ; ++i){
                if(i == u.lift)
                    continue;
                if(u.w > dist[u.f][i])
                    continue;
                for(auto v : adj[u.f][i]){
                    if(dist[u.f][u.lift] + v.second  + 60 < dist[v.first][i]){
                        dist[v.first][i] = dist[u.f][u.lift] + v.second + 60;
                        pq.push(node(dist[v.first][i] , v.first , i));
                    }
                }
            }
        }

        ll res = inf;
        for(int i = 0 ; i < n ; ++i){
            res = min(res , dist[k][i]);
        }
        if(res == inf){
            printf("IMPOSSIBLE\n");
        }
        else
            printf("%lld\n" , res);


        for(int j = 0 ; j < 101 ; ++j){
            for(int i = 0; i < n ; ++i){
                adj[j][i].clear();
            }
        }

    }



return 0;
}
