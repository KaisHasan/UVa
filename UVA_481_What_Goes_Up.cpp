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

int n;
int a[MAX];
int r[MAX];
int len[MAX];
int res;

int Bin_s(int en, int s){
        int start = 0;
        int middle;
        int l = en;
        while(start <= en){
            middle = (start + en)/2;
            if(middle < l && a[len[middle]] < s && s <= a[len[middle+1]]){
                return middle+1;
            }else if(a[len[middle]] < s){
                start = middle+1;
            }else{
                en = middle-1;
            }
        }
        return -1;
}

void LIS(){
    memset(r , -1 , sizeof(r));
    len[0] = 0;
    res = 0;
    for(int i = 1 ; i < n ; ++i){
        if(a[i] > a[len[res]]){
            ++res;
            len[res] = i;
            r[len[res]] = len[res-1];
        }
        else if(a[i] < a[len[0]]){
            len[0] = i;
        }
        else{
            int index = Bin_s(res ,a[i]);
            len[index] = i;
            r[len[index]] = len[index - 1];
        }
    }
    ++res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
n = 0;
while(sc(a[n++]) != EOF);
LIS();
printf("%d\n-\n" , res);
int i = len[res - 1];
stack<int> res;
while(i != -1){
    res.push(a[i]);
    i = r[i];
}
while(!res.empty()){
    printf("%d\n" , res.top());
    res.pop();
}


return 0;
}
