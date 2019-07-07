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
    int w , u;
    char lst;
    node(int _w , int _u , char _lst){
        w = _w;
        u = _u;
        lst = _lst;
    }
    node(const node& temp){
        w = temp.w;
        u = temp.u;
        lst = temp.lst;
    }
    friend bool operator<(const node a , const node b){
        return a.w > b.w;
    }
};

map<string ,int> trans;
vector<node> adj[MAX];
int dist[MAX];

int main(){
freopen("output.txt" , "w" , stdout);
freopen("input.txt" , "r" , stdin);

    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        string s1 , s2;
        cin>>s1>>s2;
        int cur = 0;
        trans[s1] = ++cur;
        int st = cur;
        trans[s2] = ++cur;
        int en = cur;
        for(int i = 0 ; i < n; ++i){
            string s , t;
            cin>>s>>t;
            if(trans.find(s) == trans.end())
                trans[s] = ++cur;
            if(trans.find(t) == trans.end())
                trans[t] = ++cur;
            int u = trans[s];
            int v = trans[t];
            string word;cin>>word;
            int w = word.size();
            adj[u].pb(node(w , v , word[0]));
            adj[v].pb(node(w , u , word[0]));
        }
        fill(dist , dist + MAX , inf);
        dist[st] = 0;
        priority_queue<node , vector<node> > pq;
        pq.push(node(0 , st , '*'));
        while(!pq.empty()){
            int u = pq.top().u;
            int w = pq.top().w;
            char lst = pq.top().lst;
            pq.pop();
            if(w > dist[u])
                continue;
            for(auto e : adj[u]){
                if(e.lst == lst)
                    continue;
                if(dist[u] + e.w < dist[e.u]){
                    dist[e.u] = dist[u] + e.w;
                    pq.push(node(dist[e.u] , e.u , e.lst));
                }
            }
        }
        if(dist[en] == inf)
            printf("impossivel\n");
        else
            printf("%d\n" , dist[en]);
        for(int i = 0 ; i <= n ; ++i)
            adj[i].clear();
        trans.clear();
    }



return 0;
}
