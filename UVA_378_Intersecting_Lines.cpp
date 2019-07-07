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
    void input(){
        double a , b;
        scd(a);scd(b);
        x = a;
        y = b;
    }
};

struct line {
    double a , b , c;
    line(int _a = 0 , int _b = 0 , int _c  = 0){
        a =_a;
        b = _b;
        c = _c;
    }
    line(const line& l){
        a = l.a;
        b = l.b;
        c = l.c;
    }
};

void points_to_line(point p1 , point p2 , line &l){
    if(fabs(p1.x - p2.x) < eps){
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    }
    else{
        l.a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1 , line l2){
    return (fabs(l1.a - l2.a) < eps) && (fabs(l1.b - l2.b) < eps);
}

bool areSame(line l1 , line l2){
    return areParallel(l1 , l2) && (fabs(l1.c - l2.c) < eps);
}

int areIntersect(line l1 , line l2 , point &p){
    if(areSame(l1 , l2))
        return 0;
    if(areParallel(l1 , l2))
        return -1;
    //solve system of two linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    //special case : test for vertical line to avoid division by zero
    if(fabs(l1.b) > eps)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return 1;
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
printf("INTERSECTING LINES OUTPUT\n");
    int t;
    sc(t);
    while(t--){
        point p1 , p2 , p3 , p4;
        p1.input();
        p2.input();
        p3.input();
        p4.input();
        line l1;
        points_to_line(p1 , p2 , l1);
        line l2;
        points_to_line(p3 , p4 , l2);
        point intersect_point;
        int res = areIntersect(l1 , l2 , intersect_point);
        if(res == 0)
            printf("LINE\n");
        else if(res == -1)
            printf("NONE\n");
        else
            printf("POINT %.2f %.2f\n" , intersect_point.x , intersect_point.y);
    }



printf("END OF OUTPUT\n");
return 0;
}
