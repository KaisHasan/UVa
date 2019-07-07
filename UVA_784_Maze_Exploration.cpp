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

int m , n;
char grid[101][101];
int vis[101][101];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
int nCol[101];
int valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < nCol[x] && (grid[x][y] == ' ' || grid[x][y] == '*') && vis[x][y] == 0;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        mem(vis , 0);
        n = 0;
        pi st;
        string s;
        while(1){
            s.clear();
            getline(cin , s);
            if(s.size() < 1)
                continue;
            if(s[0] == '_')
                break;
            nCol[n] = s.size();
            for(int i = 0; i < nCol[n] ; ++i){
                grid[n][i] = s[i];
                if(s[i] == '*')
                    st = MP(n, i);
            }
            ++n;
        }
        queue<pi> q;
        q.push(st);
        vis[st.first][st.second] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            grid[x][y] = '#';
            for(int i = 0 ; i < 4 ; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(valid(nx , ny)){
                    vis[nx][ny] = 1;
                    q.push(MP(nx , ny));
                }
            }
        }
        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < nCol[i] ; ++j)
                printf("%c" , grid[i][j]);
            blank;
        }
        printf("%s" , s.c_str());
        blank;
    }



return 0;
}
