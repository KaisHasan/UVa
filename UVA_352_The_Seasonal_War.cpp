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
const double PI = 3.14159265359;
const double eps = 1e-7;

int vis[31][31];
int grid[31][31];
int n , m;
int dx[] = {1 , -1, 0 , 0 , 1 , -1 , 1 , -1};
int dy[] = {0 , 0 , -1, 1 , 1 , -1 , -1 , 1};
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1 && vis[x][y] == 0;
}
int cnt;
void dfs(int x , int y){
    vis[x][y] = 1;
    for(int i = 0 ; i < 8 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx  ,ny)){
            dfs(nx , ny);
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
while(sc(n) != EOF){
    m = n;
    ++cases;
    for(int i = 0 ; i < n ; ++i){
        string s;cin>>s;
        for(int j  = 0 ; j < n ; ++j){
            grid[i][j] = int(s[j] - '0');
        }
    }
    mem(vis , 0);
    cnt = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(!vis[i][j] && grid[i][j] == 1){
                ++cnt;
                dfs(i , j);
            }
        }
    }
    printf("Image number %d contains %d war eagles.\n", cases , cnt);
}



return 0;
}
