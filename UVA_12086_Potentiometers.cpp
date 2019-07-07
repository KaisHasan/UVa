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
#define sch(a) scanf("%*[ \t\n]%c",&a)
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


int a[2*MAX];
int tree[2*4*MAX];

void build(int p , int l , int r){
    if(l == r){
        tree[p] = a[l];
        return;
    }
    int md = (l+r)>>1;
    build(p * 2 , l , md);
    build(p * 2+ 1 , md + 1 , r);
    tree[p] = tree[p*2] + tree[p*2+1];
}

void update(int p , int l , int r , int pos){
    if(l > pos || r < pos)
        return;
    if(l == r && l == pos){
        tree[p] = a[l];
        return;
    }
    int md = (l + r)>>1;
    update(p * 2 , l , md , pos);
    update(p * 2+ 1 , md + 1 ,r , pos);
    tree[p] = tree[p*2] + tree[p*2+1];
}

int qwr(int p , int l , int r , int st , int en){
    if(l > en || r < st)
        return 0;
    if(l >= st && r <= en)
        return tree[p];
    int md = (l + r )>>1;
    return qwr(p * 2 , l , md ,st , en) + qwr(p * 2 + 1 , md + 1 , r , st , en);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int cases = 0;
    char op[4], cmd[50];
    int x , y;
    while(1){
        int n ;
        sc(n);
        if(!n)
            break;
        if(cases)
            blank;
        printf("Case %d:\n" , ++cases);
        for(int i = 0 ; i < n ; ++i){
            sc(a[i]);
        }
        build(1 , 0 , n- 1);
        int x , y;
        getchar();
        while (gets(cmd)) {
            if(cmd[0] == 'E')
                break;
            sscanf(cmd, "%s %d %d", op, &x, &y);
            if(op[0] == 'M'){
                int res = qwr(1 , 0 , n -1 , x - 1 , y - 1);
                printf("%d\n" , res);
            }
            else{
                int pos = x;
                a[pos - 1] = y;
                update(1 , 0 , n - 1 , pos - 1);
            }
        }

    }




return 0;
}
