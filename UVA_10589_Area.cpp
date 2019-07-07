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
const double eps = 1e-10;

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {} };      // constructor

bool insideCircle(point p, point c, double r) { // all integer version
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
    return (Euc <= rSq);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        int n , a;
        sc(n);sc(a);
        if(!n && !a)
            break;
        int m = 0;
        for(int i = 0 ; i < n ; ++i){
            double x , y;
            scd(x);scd(y);
            point p(x,y);
            if(!insideCircle(p , point(0,0) , a))
                continue;
            if(!insideCircle(p , point(a,0) , a))
                continue;
            if(!insideCircle(p , point(0,a) , a))
                continue;
            if(!insideCircle(p , point(a,a) , a))
                continue;
            ++m;
        }
        double res = ((double)m/(double)n)*(double)a*(double)a;
        printf("%.5f\n" , res);
    }




return 0;
}
