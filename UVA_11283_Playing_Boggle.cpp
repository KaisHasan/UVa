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

int n ,m;
string a[MAX];
int dx[] = {-1 , 1 , 0 , 0 , -1 , 1 , -1 , 1};
int dy[] = {0 , 0 , -1 , 1 , 1 , -1 , -1 , 1};
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
string s;
bool f;
int vis[200][200];
void solve(int x , int y ,int id){
    if(id == (int)s.size()){
        f = true;
        return;
    }
    if(f)
        return;
    for(int i = 0 ; i < 8 && !f; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx , ny) && s[id] == a[nx][ny] && !vis[nx][ny]){
            vis[nx][ny] = 1;
            solve(nx , ny , id + 1);
            vis[nx][ny] = 0;
        }
    }
}

int score(int x){
    if(x == 3 || x == 4)
        return 1;
    if(x == 5)
        return 2;
    if(x == 6)
        return 3;
    if(x == 7)
        return 5;
    if(x >= 8)
        return 11;
    return 0;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
int cases = 0;
while(t--){
    n = 4;m = 4;
    for(int i = 0 ; i < n ;++i){
        a[i].clear();
        cin>>a[i];
    }
    int k;
    sc(k);
    int res = 0;
    while(k--){
        s.clear();
        cin>>s;
        f = false;
        for(int i = 0 ; i < n && !f; ++i){
            for(int j = 0 ; j < m && !f; ++j){
                if(a[i][j] == s[0]){
                    vis[i][j] = 1;
                    solve(i , j , 1);
                    vis[i][j] = 0;
                }
            }
        }
        if(f){
            res += score((int)s.size());
        }
    }
    printf("Score for Boggle game #%d: %d\n" ,++cases , res);
}

return 0;
}
