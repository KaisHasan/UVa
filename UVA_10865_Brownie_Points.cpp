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

struct point{
    int x , y;
    point(){x = y = 0;}
    point(int _x , int _y){
        x = _x;
        y = _y;
    }
};

point a[2 * MAX];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        for(int i = 0; i < n ; ++i){
            int x , y;
            sc(x);sc(y);
            a[i] = point(x ,y);
        }
        point md = a[n / 2];
        int stan = 0, ollie = 0;
        for(int i = 0 ; i < n ; ++i){
            if(a[i].x == md.x || a[i].y == md.y)
                continue;
            if(a[i].x > md.x && a[i].y > md.y)
                ++stan;
            else if(a[i].x < md.x && a[i].y < md.y)
                ++stan;
            else if(a[i].x < md.x && a[i].y > md.y)
                ++ollie;
            else if(a[i].x > md.x && a[i].y < md.y)
                ++ollie;
        }
        printf("%d %d\n" , stan , ollie);
    }



return 0;
}
