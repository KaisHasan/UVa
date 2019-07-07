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
const double PI = 3.14159265359;
const double eps = 1e-9;

struct point{
    double x , y;
    point(){x = y = 0.0;}
    point(double _x , double _y){
        x = _x;
        y = _y;
    }
    point(const point& temp){
        x = temp.x;
        y = temp.y;
    }
    bool operator<(point other) const{
        if(fabs(x - other.x) > eps)
            return x < other.x;
        return y < other.y;
    }
    bool operator==(point other) const{
        return (fabs(x - other.x) < eps && fabs(y - other.y) < eps);
    }
};

int n;
point upleft[12];
point botright[12];

bool is_inside(point p , point p1 , point p2){
    return (p.x - p1.x > eps && p2.x - p.x > eps && p1.y - p.y > eps && p.y - p2.y > eps);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

char c;
n = 0;
while(1){
    cin>>c;
    if(c == '*')
        break;
    double x, y;
    cin>>x>>y;
    upleft[n] = point(x ,y);
    double x1,y1;
    cin>>x1>>y1;
    botright[n] = point(x1 , y1);
    ++n;
}

point test(9999.9 , 9999.9);
int cases = 0;
while(1){
    double x , y;
    scd(x);scd(y);
    point p(x , y);
    if(p == test)
        break;
    ++cases;
    int cnt = 0;
    for(int i = 0 ; i < n ; ++i){
        if(is_inside(p , upleft[i] , botright[i])){
            printf("Point %d is contained in figure %d\n" , cases , i + 1);
            ++cnt;
        }
    }
    if(!cnt)
        printf("Point %d is not contained in any figure\n" , cases);
}



return 0;
}
