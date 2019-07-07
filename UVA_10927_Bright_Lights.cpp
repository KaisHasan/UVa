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

struct point { double x, y,z;   // only used if more precision is needed
  point() { x = y = z = 0.0; }                      // default constructor
  point(double _x, double _y , double _z = 0.0) : x(_x), y(_y) ,z(_z) {}        // user-defined
  point(const point& p){
    x = p.x;
    y = p.y;
    z = p.z;
  }
};
double dist(point p1, point p2) {                // Euclidean distance
                      // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double
vector<point> points;
int rot(point a , point b){
    double ta = atan2(a.y,a.x);
    double tb = atan2(b.y,b.x);
    if(ta - tb > eps){
        return 1;
    }
    else if(tb - ta > eps)
        return 0;
    return -1;
}
bool cmp(point a , point b){
    int res = rot(a , b);
    if(res != -1)
        return res;
    return dist(b , point(0,0)) - dist(a , point(0,0)) > eps;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases =0;

    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        points.clear();
        for(int i = 0 ;  i< n ; ++i){
            double x, y , z;
            scd(x);scd(y);scd(z);
            points.pb(point(x,y,z));
        }
        sort(all(points) , cmp);
        vpi res;
        res.clear();
        vector<point> v;
        for(int i = 0 ; i < n ;){
            v.clear();
            int j = i + 1;
            v.pb(points[i]);
            while(j < n && rot(points[j] , points[j-1]) == -1){
                v.pb(points[j]);
                ++j;
            }
            int mx = -1;
            for(auto p : v){
                if(p.z <= mx){
                    res.pb(MP((int)p.x,(int)p.y));
                    continue;
                }
                mx = max(mx , (int)p.z);
            }
            i = j;
        }
        printf("Data set %d:\n",++cases);
        if(!res.empty()){
            sort(all(res));
            printf("Some lights are not visible:\n");
            int id = 0;
            for(auto p : res){
                ++id;
                printf("x = %d, y = %d" , p.first,p.second);
                if(id == (int)res.size())
                    printf(".\n");
                else
                    printf(";\n");
            }
        }
        else{
            printf("All the lights are visible.\n");
        }


    }




return 0;
}
