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

int n , m;
int a[50][50];
string s;
bool exist;
int solve(){
    for(int i = 0; i < n ; ++i){
        for(int j= 1 ; j < m ; ++j){
            a[i][j] += a[i][j-1];
        }
    }
    int sum = 0;
    int mxSum = 0;
    for(int j1 = 0 ; j1 < m ; ++j1){
        for(int j2 = j1 ; j2 < m ; ++j2){
            int sum = 0;
            for(int i = 0 ; i < n; ++i){
                int temp = a[i][j2] - ((j1 > 0)? a[i][j1-1] : 0);
                if(temp < j2 - j1 + 1)
                    sum = 0;
                else{
                    sum += temp;
                }
                mxSum = max(mxSum , sum);
            }
        }
    }
    return mxSum;
}


int main(){


//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
getline(cin , s);
getline(cin , s);
    while(t--){
        n = 0;
        exist = false;
        while(1){
            s.clear();
            getline(cin , s);
            if(s.size() < 1)
                break;
            m = s.size();
            for(int i = 0 ; i < m ; ++i){
                a[n][i] = (s[i] == '1');
                if(a[n][i])
                    exist = true;
            }
            ++n;
            s.clear();
        }
        int res = solve();
        if(exist && !res){
            res = 1;
        }
        printf("%d\n" , res);
        if(t)
            blank;
    }



return 0;
}
