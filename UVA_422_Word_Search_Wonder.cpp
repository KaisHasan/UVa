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

int n;
string a[MAX];
int dx[] = {-1 , 1 , 0 , 0 , -1 , 1 , -1 , 1};
int dy[] = {0 , 0 , -1 , 1 , 1 , -1 , -1 , 1};
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}
string s;
pi ans;
bool f;
void solve(int x , int y , int dir , int id){
    if(id == (int)s.size()){
        ans = MP(x,y);
        f = true;
        return;
    }
    if(f)
        return;
    if(dir == -1){
        for(int i = 0 ; i < 8 && !f; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx , ny) && s[id] == a[nx][ny]){
                solve(nx , ny , i , id + 1);
            }
        }
    }
    else if(!f){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(valid(nx , ny) && a[nx][ny] == s[id])
            solve(nx , ny , dir , id + 1);
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ;++i)
        cin>>a[i];
    while(1){
        s.clear();
        cin>>s;
        if(s == "0")
            break;
        f = false;
        for(int i = 0 ; i < n && !f; ++i){
            for(int j = 0 ; j < n && !f; ++j){
                if(a[i][j] == s[0]){
                    solve(i , j , -1 , 1);
                    if(f){
                        printf("%d,%d %d,%d" , i + 1, j + 1, ans.first + 1, ans.second + 1);
                    }
                }
            }
        }
        if(!f)
            printf("Not found");
        blank;
    }



return 0;
}
