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
#define INF 1e9
#define EPS 1e-9
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , m;
char grid[50][50];
int dist[16][16];
vpi B , X;
int vis[50][50];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}

void BFS(int id){
    pi st = B[id];
    mem(vis , -1);
    vis[st.first][st.second] = 0;
    queue<pi> q;
    q.push(st);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx,ny) && vis[nx][ny] == -1){
                vis[nx][ny] = vis[x][y] + 1;
                q.push(MP(nx,ny));
            }
        }
    }
    for(int i = 0 ; i < (int)X.size() ; ++i){
        int u = X[i].first;
        int v = X[i].second;
        dist[id][i] = vis[u][v];
        if(dist[id][i] == -1)
            dist[id][i] = inf;
    }
}

int dp[16][1<<16];

int solve(int id , int mask){
    if(id == n){
        return 0;
    }
    int &res = dp[id][mask];
    if(res != -1)
        return res;
    res = inf;
    for(int i = 0 ; i < m ; ++i){
        if(mask & (1<<i))
            continue;
        res = min(res , solve(id + 1 , mask | (1<<i)) + dist[id][i]);
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        sc(n);sc(m);
        for(int i = 0 ; i < n ; ++i){
            string s;
            cin>>s;
            for(int j = 0 ; j < m ; ++j){
                grid[i][j] = s[j];
                if(s[j] == 'B'){
                    B.pb(MP(i,j));
                }
                else if(s[j] == 'X'){
                    X.pb(MP(i,j));
                }
            }
        }

        for(int i = 0 ; i < (int)B.size() ; ++i){
            BFS(i);
        }
        n = B.size();
        m = X.size();
        mem(dp,-1);
        int res = solve(0,0);
        printf("%d\n" , res);

        B.clear();
        X.clear();
        mem(dist , 0);
    }



return 0;
}
