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
const double eps = 1e-7;

double DEG_to_RAD(double d) { return d * PI / 180.0; }


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    double l , w , h , phi;
    while(scanf("%lf %lf %lf %lf" , &l , &w , &h , &phi) != EOF){
        phi = DEG_to_RAD(phi);
        if(l * tan(phi) - h > eps){
            double A = (PI/2.0) - phi;
            double C = (PI/2.0) - A;
            double a = (h * sin(A))/sin(C);
            double area = 0.5 * h * a;
            double vol = area * w;
            printf("%.3f mL\n" , vol);
        }
        else{
            double a = l * tan(phi);
            double area = (0.5 * ((2.0*h) - a)) * l;
            double vol = area * w;
            printf("%.3f mL\n" , vol);
        }
    }




return 0;
}
