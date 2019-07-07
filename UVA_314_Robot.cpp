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


struct node{
    int x , y , dir , time;
    node(int _x = 0 , int _y = 0 , int _dir = 0 , int _time = 0){
        x = _x;
        y = _y;
        dir = _dir;
        time = _time;
    }
    node(const node& temp){
        x = temp.x;
        y = temp.y;
        dir = temp.dir;
        time = temp.time;
    }
};
int n , m;
int grid[55][55];
int dis[55][55][5];
//      north,right,south,left
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int cx[] ={-1,-1,0,0};
int cy[] ={-1,0,-1,0};
bool valid(int x , int y , int dir){
    bool test = (x > 0 && y > 0 && x < n && y < m);
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + cx[i];
        int ny = y + cy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            test = test && (grid[nx][ny] == 0);
        }
    }
    return test;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        sc(n);sc(m);
        if(!n && !m)
            break;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j)
                sc(grid[i][j]);
        }
        int x , y;
        sc(x);sc(y);
        pi t;
        sc(t.first);sc(t.second);
        string s;
        s.clear();
        cin>>s;
        int dir;
        if(s == "north"){
            dir = 0;
        }
        else if(s == "east")
            dir = 1;
        else if(s == "south")
            dir = 2;
        else
            dir = 3;
        mem(dis , -1);
        node st(x , y , dir , 0);
        queue<node> q;
        q.push(st);
        dis[st.x][st.y][st.dir] = 0;
        int res_dir = 0;
        int res = -1;
        while(!q.empty()){
            node v = q.front();
            q.pop();
            if(v.x == t.first && v.y == t.second){
                res = v.time;
                break;
            }
            //////
            if(dis[v.x][v.y][(v.dir + 1)%4] == -1){
                dis[v.x][v.y][(v.dir + 1)%4] = dis[v.x][v.y][v.dir] + 1;
                q.push(node(v.x , v.y , (v.dir + 1)%4 , v.time + 1));
            }
            //////
            if(dis[v.x][v.y][(v.dir + 3)%4] == -1){
                dis[v.x][v.y][(v.dir + 3)%4] = dis[v.x][v.y][v.dir] + 1;
                q.push(node(v.x , v.y , (v.dir + 3)%4 , v.time + 1));
            }
            //////
            for(int i = 1 ; i < 4 ; ++i){
                int nx = v.x + (dx[v.dir]*i);
                int ny = v.y + (dy[v.dir]*i);
                if(valid(nx , ny , v.dir)){
                    if(dis[nx][ny][v.dir] != -1)
                        continue;
                    dis[nx][ny][v.dir] = dis[v.x][v.y][v.dir] + 1;
                    q.push(node(nx , ny , v.dir , v.time + 1));
                }
                else
                    break;
            }
        }
        printf("%d\n" , res);
        while(!q.empty())
            q.pop();

    }



return 0;
}
