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

int n , m;
char grid[11][11];
int vis[11][11];
string s = "IEHOVA#";
int dy[] = {1 , -1 , 0};
int dx[] = {0 , 0 ,  -1};
bool valid(int x  , int y , int id){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == s[id] && vis[x][y] == 0;
}
string res[] = {"right" , "left" , "forth"};
void dfs(int x , int y , int id){
    vis[x][y] = 1;
    for(int i = 0 ; i < 3 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx , ny , id)){
            cout<<res[i];
            if(id != s.size() - 1)
                cout<<' ';
            dfs(nx , ny , id + 1);
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
    while(t--){
        sc(n);sc(m);
        int x , y;
        mem(vis , 0);
        for(int i = 0 ; i < n ; ++i){
            string s;cin>>s;
            for(int j = 0 ; j < m ; ++j){
                grid[i][j] = s[j];
                if(s[j] == '@'){
                    x = i;y = j;
                }
            }
        }
        dfs(x , y , 0);
        blank;
    }



return 0;
}
