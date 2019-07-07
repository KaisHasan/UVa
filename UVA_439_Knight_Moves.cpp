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

int dis[11][11];
int dx[] = {2 , 2 , 1,  -1, -2 , -2, 1, -1};
int dy[] = {1 , -1 ,2 , 2 , 1 , -1, -2 , -2};
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < 8 && y < 8 && dis[x][y] == 0;
}
int BFS(pi st , pi en){
    mem(dis , 0);
    queue<pi> q;
    q.push(st);
    dis[st.first][st.second] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == en.first && y == en.second){
            return dis[x][y] - 1;
        }
        for(int i = 0 ; i < 8 ; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx , ny)){
                q.push(MP(nx , ny));
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        string s;
        getline(cin , s);
        if(s.size() < 1)
            break;
        pi st;
        st.second = s[0] - 'a';
        st.first = (s[1] - '0') - 1;
        pi en;
        en.second = s[3] - 'a';
        en.first = (s[4] - '0') - 1;
        //printf("st.x = %d    , st.y  =  %d\n" , st.first , st.second);
        //printf("en.x = %d    , en.y  =  %d\n" , en.first , en.second);
        int res = BFS(st , en);
        printf("To get from %c%c to %c%c takes %d knight moves.\n", s[0] , s[1] , s[3] , s[4] , res);
    }



return 0;
}
