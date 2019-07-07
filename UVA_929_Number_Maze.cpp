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

int dist[1000][1000];
int grid[1000][1000];
struct node{
    int x , y , w;
    node(int _x = 0 , int _y = 0 , int _w = 0){
        x = _x;
        y = _y;
        w = _w;
    }
    node(const node& temp){
        x = temp.x;
        y = temp.y;
        w = temp.w;
    }
    friend bool operator>(const node a , const node b){
        return a.w < b.w;
    }
    friend bool operator<(const node a , const node b){
        return a.w > b.w;
    }
};

//bool cmp(node a , node b){
//    return a.w > b.w;
//}
int n ,m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int valid(int x , int y){
    return x >= 0 && y >= 0 && x  < n && y < m;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        sc(n);sc(m);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j)
                sc(grid[i][j]);
        }
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < m ; ++j)
                dist[i][j] = inf;
        dist[0][0] = grid[0][0];
        priority_queue<node> pq;
        pq.push(node(0 , 0 , grid[0][0]));
        while(!pq.empty()){
            node v = pq.top();
            pq.pop();
            if(v.w > dist[v.x][v.y])
                continue;
            for(int i = 0 ; i < 4 ; ++i){
                int nx = v.x + dx[i];
                int ny = v.y + dy[i];
                if(!valid(nx ,ny))
                    continue;
                if(dist[v.x][v.y] + grid[nx][ny] < dist[nx][ny]){
                    dist[nx][ny] = dist[v.x][v.y] + grid[nx][ny];
                    pq.push(node(nx , ny , dist[nx][ny]));
                }
            }
        }
        printf("%d\n" , dist[n-1][m-1]);

    }



return 0;
}
