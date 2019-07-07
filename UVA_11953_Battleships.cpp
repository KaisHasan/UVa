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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n;
int cnt;
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1, 1};
int vis[111][111];
char grid[111][111];
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == 0 && grid[x][y] != '.';
}
void dfs(int x , int y){
    vis[x][y] = 1;
    if(grid[x][y] == 'x')
        ++cnt;
    for(int i = 0 ;i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx , ny)){
            dfs(nx , ny);
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
int cases = 1;
while(t--){
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        string s;cin>>s;
        for(int j = 0 ; j < n ; ++j){
            grid[i][j] = s[j];
        }
    }

    int res = 0;
    mem(vis, 0);
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(grid[i][j] != '.' && vis[i][j] == 0){
                cnt = 0;
                dfs(i ,j);
                if(cnt)
                    ++res;
            }
        }
    }
    printf("Case %d: %d\n" , cases++ , res);
}



return 0;
}
