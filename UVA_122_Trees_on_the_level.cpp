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
const int MAX = 1e6+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int tree[4 * MAX];
bool vis[4 * MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    char t[500];
    while(scanf("%s" ,&t) != EOF){
        mem(tree , -1);
        mem(vis , 0);
        char s[500];
        int n;
        bool test = true;
        int max_pos = 1;
        while(1){
            if (strcmp(t, "()")==0)
                break;
            sscanf(t , "(%d,%s)" ,&n , &s);
            int len = strlen(s);
            int pos = 1;
            for(int i = 0 ;i < len - 1 ; ++i){
                if(s[i] == 'R'){
                    pos = 2 * pos + 1;
                }
                else
                    pos = 2 * pos;
            }
            if(tree[pos] != -1)
                test = false;
            tree[pos] = n;
            max_pos = max(max_pos , pos);
            scanf("%s", &t);
        }
        vector<int> res;
        vis[1] = 1;
        for(int i = 1 ; i <= max_pos ; ++i){
            if(tree[i] == -1)
                continue;
            if(vis[i] == 0){
                test = false;
                break;
            }
            vis[2 * i] = 1;
            vis[2 * i + 1] = 1;
            res.pb(tree[i]);
        }
        if(test){
            printf("%d" , res[0]);
            for(int i = 1 ; i < res.size(); ++i){
                printf(" %d" , res[i]);
            }
            blank;
        }
        else{
            printf("not complete\n");
        }
    }


return 0;
}
