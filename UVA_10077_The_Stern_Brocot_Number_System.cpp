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
const double eps = 1e-9;

struct node{
    int x , y;
    node(int a = 1 , int b = 1){
        x = a;
        y = b;
    }
    node(const node& temp){
        x = temp.x;
        y = temp.y;
    }
    friend node operator+(node a , node b){
        node temp;
        temp.x = a.x + b.x;
        temp.y = a.y + b.y;
        return temp;
    }
    friend bool operator<(node a , node b){
        double resa = (double)(a.x)/(double)(a.y);
        double resb = (double)(b.x)/(double)(b.y);
        return (resb - resa > eps);
    }
    friend bool operator==(node a , node b){
        return (a.x == b.x && a.y == b.y);
    }
};



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        node ML(0 , 1) , MR(1 ,0) , cur;
        string res = "";
        int x , y;
        sc(x);sc(y);
        node n(x , y);
        if(n == cur)
            break;
        while(1){
            cur = ML + MR;
            if(n == cur)
                break;
            if(n < cur){
                MR = cur;
                res += "L";
            }
            else{
                ML = cur;
                res += "R";
            }
        }
        printf("%s\n" ,res.c_str());
    }



return 0;
}
