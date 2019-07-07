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

int n , m;
int grid[1005][1005];
int dist[1005][1005];
int dx[] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
int dy[] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int Dijkstra(pi st , pi en){
    for(int i = 0 ; i <=n  ;++i)
        fill(dist[i] , dist[i] + m + 1 , inf);
    priority_queue<pair<int , pi> , vector<pair<int , pi> > , greater<pair<int , pi>> > pq;
    pq.push(MP(0,st));
    dist[st.first][st.second] = 0;
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();
        if(w > dist[x][y])
            continue;
        for(int i = 0 ; i < 8 ; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!valid(nx , ny))
                continue;
            int cost = (i != grid[x][y]);
            if(w + cost < dist[nx][ny]){
                dist[nx][ny] = w + cost;
                pq.push(MP(dist[nx][ny] , MP(nx,ny)));
            }
        }
    }
    return dist[en.first][en.second];
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid[i][j] = s[j] - '0';
        }
    }
    int q;sc(q);
    while(q--){
        pi st , en;
        sc(st.first);sc(st.second);
        sc(en.first);sc(en.second);
        --st.first;--st.second;
        --en.first;--en.second;
        int res = Dijkstra(st ,en);
        printf("%d\n" ,res);
    }



return 0;
}
