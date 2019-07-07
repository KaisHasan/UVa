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
const double eps = 1e-7;

struct point{
    double x , y;
    point(){x = y = 0.0;}
    point(double _x , double _y){
        x = _x;
        y = _y;
    }
    bool operator<(point other) const{
        if(fabs(x - other.x) > eps)
            return x < other.x;
        return y < other.y;
    }
    bool operator==(point other) const{
        return (fabs(x - other.x) < eps && fabs(y - other.y) < eps);
    }
    point operator+(point other) const{
        return point(x + other.x , y + other.y);
    }
    point operator-(point other) const{
        return point(x - other.x , y - other.y);
    }
};

point a[4];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
double x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4;
while(1){
    for(int i = 0 ; i < 4 ; ++i){
        if(scd(a[i].x) == EOF)
            return 0;
        scd(a[i].y);
    }
    int id[2] = {};
    for(int i = 0 ; i < 4 ; ++i){
        for(int j = 0 ; j < 4 ; ++j){
            if(a[i] == a[j] && i != j){
                id[0] = i;
                id[1] = j;
            }
        }
    }
    int not_id[2] = {};
    int k = 0;
    for(int i = 0 ; i < 4 ; ++i){
        if(i != id[0] && i != id[1])
            not_id[k++] = i;
    }
    point t1 = a[not_id[0]] - a[id[0]];
    point t2 = a[not_id[1]] - a[id[1]];
    point t = t1 + t2;
    t = t + a[id[0]];
    printf("%.3f %.3f\n" , t.x , t.y);


}

return 0;
}
