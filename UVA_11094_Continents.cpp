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

int n , m;
char land;
char grid[32][32];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
int vis[32][32];
int mod(int y){
    return (y + m)%m;
}
bool valid(int x , int y){
    return x >= 0 && x < n && vis[x][y] == 0 && grid[x][y] == land;
}
int cnt;
void dfs(int x , int y){
    vis[x][y] = 1;
    ++cnt;
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        ny = mod(ny);
        if(valid(nx , ny)){
            dfs(nx , ny);
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

while(scanf("%d %d" , &n , &m) != EOF){
    for(int i = 0 ; i < n ; ++i){
        string s;cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid[i][j] = tolower(s[j]);
        }
    }
    int stx , sty;
    sc(stx);sc(sty);
    mem(vis , 0);
    land = grid[stx][sty];
    dfs(stx , sty);
    int res = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(!vis[i][j] && grid[i][j] == land){
                cnt = 0;
                dfs(i , j);
                res = max(res, cnt);
            }
        }
    }
    printf("%d\n" , res);
}



return 0;
}
