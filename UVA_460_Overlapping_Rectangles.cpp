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
    int x , y;
    point(){x = y = 0;}
    point(int _x , int _y){
        x = _x;
        y = _y;
    }
};



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
while(t--){
    int x1 , y1 , x2 , y2;
    sc(x1);sc(y1);sc(x2);sc(y2);
    point ll1(x1 , y1) , ur1(x2 , y2);
    sc(x1);sc(y1);sc(x2);sc(y2);
    point ll2(x1 , y1) , ur2(x2 , y2);

    if(ur1.x > ur2.x){
        if(ur2.x > ll1.x && ur2.y > ll1.y && ur1.y > ll2.y){
            point res1 , res2;
            res1.x = max(ll1.x , ll2.x);;
            res2.x = min(ur1.x , ur2.x);
            res1.y = max(ll1.y , ll2.y);
            res2.y = min(ur1.y , ur2.y);
            printf("%d %d %d %d\n" , res1.x , res1.y , res2.x , res2.y);
        }
        else{
            printf("No Overlap\n");
        }
    }
    else{
        if(ur1.x > ll2.x && ur1.y > ll2.y && ur2.y > ll1.y){
            point res1 , res2;
            res1.x = max(ll1.x , ll2.x);
            res2.x = min(ur1.x , ur2.x);
            res1.y = max(ll1.y , ll2.y);
            res2.y = min(ur1.y , ur2.y);
            printf("%d %d %d %d\n" , res1.x , res1.y , res2.x , res2.y);
        }
        else{
            printf("No Overlap\n");
        }
    }


    if(t)
        blank;
}



return 0;
}
