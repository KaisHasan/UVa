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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;


vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool leapYear(int yy){
        if ((yy % 400 == 0) || (yy % 100 != 0 && yy % 4 == 0))
            return 1;
        else
            return 0;
}
int days_of_month(int m , int y){
        if(m != 2)
            return months[m];
        return months[m] + leapYear(y);
}
class date{
    int day , month , year;
public:
    date(int d = 1  , int m = 1 , int y = 1900){
        day = d;
        month = m;
        year  = y;
    }
    date(const date& temp){
        day = temp.day;
        month = temp.month;
        year = temp.year;
    }


    friend int operator-(date a , date b){
        int res1 = a.day;
        int res2 = b.day;
        for(int i = a.month - 1 ; i > 0 ; --i)
            res1 += days_of_month(i , a.year);
        for(int i = b.month - 1 ; i > 0 ; --i)
            res2 += days_of_month(i , b.year);
        if(a.year - b.year == 1){
            res1 += 365 + leapYear(a.year - 1);
            --a.year;
        }
        if(res1 - res2 == 1 && a.year == b.year)
            return 1;
        return 1000;
    }
};

date a[2000];
int c[2000];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        for(int i = 0 ; i < n ; ++i){
            int d , m , y , cost;
            sc(d);sc(m);sc(y);sc(cost);
            a[i] = date(d , m , y);
            c[i] = cost;
        }
        int res = 0;
        int cnt = 0;
        for(int i = 1 ; i < n ; ++i){
            if(a[i] - a[i-1] == 1){
                res += (c[i] - c[i-1]);
                ++cnt;
            }
        }
        printf("%d %d\n" , cnt , res);
    }



return 0;
}
