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

int n, m , tot;
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0  ,-1 , 1};
int dp[101][101][101];
bool valid(int x , int y , int t){
    return t <= tot && x >= 0 && y >= 0 && x < n && y < m && !dp[t][x][y];
}
vpi res , temp;
bool test;
void dfs(int x , int y , int t){
    temp.pb(MP(x,y));
    if(t == tot){
        if(res.empty())
            res = temp;
        else{
            for(int i = 0; i <  t ; ++i)
                if(res[i] != temp[i])
                    res[i] = MP(-1,-1);
        }
    }
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx , ny , t + 1)){
            dfs(nx , ny , t + 1);
        }
    }
    temp.pop_back();
}


int main(){
freopen("output.txt" , "w" , stdout);
freopen("input.txt" , "r" , stdin);
    int cases = 0;
    while(1){
        res.clear();
        mem(dp , 0);
        sc(m);sc(n);sc(tot);
        if(m + n + tot == 0)
            break;
        int q;
        sc(q);
        test = true;
        temp.clear();
        while(q--){
            int t , x1 , y1 , x2 , y2;
            sc(t);sc(y1);sc(x1);sc(y2);sc(x2);
            --x1;--x2;--y1;--y2;
            for(int i = x1 ; i <= x2 ; ++i){
                for(int j = y1 ; j <= y2 ; ++j){
                    dp[t][i][j] = 1;
                }
            }
        }
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(!dp[1][i][j]){
                    temp.clear();
//                    printf("%d , %d\n" , i , j);
                    dfs(i , j , 1);
                }
            }
        }
        if(!res.empty()){
            int cnt = 0;
            for(int i = 0 ; i < tot; ++i)
                if(res[i] != MP(-1,-1))
                    ++cnt;
            if(!cnt)
                test = false;
        }
        printf("Robbery #%d:\n" , ++cases);
        if(res.empty()){
            printf("The robber has escaped.");
        }
        else if(test){
            for(int i = 0; i < (int)res.size() ; ++i){
                int x = res[i].second;
                int y = res[i].first;
                if(x == -1 && y == -1)
                    continue;
                ++x;++y;
                printf("Time step %d: The robber has been at %d,%d." , i + 1 , x ,y);
                if(i != (int)res.size() - 1)
                    printf("\n");
            }
        }
        else{
            printf("Nothing known.");
        }
        blank;

    }



return 0;
}
