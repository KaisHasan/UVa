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

string s1 , s2;
string sum(){
    int n1 = s1.size();
    int n2 = s2.size();
    while(n1 < n2){
        s1 = "0" + s1;
        ++n1;
    }
    while(n2 < n1){
        s2 = "0" + s2;
        ++n2;
    }
    reverse(all(s1));
    reverse(all(s2));
    int hold = 0;
    string res = "";
    //pla;
    for(int i = 0; i < n1 ; ++i){
        res += char('0' + (((s1[i]-'0') + (s2[i]-'0') + hold) % 10));
        hold = ((s1[i]-'0') + (s2[i]-'0') + hold) / 10;
        //cout<<res<<'\t'<<hold<<endl;
    }
    //pla;
    if(hold)
        res += char('0' + hold);
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        s1.clear();
        s2.clear();
        cin>>s1>>s2;
        reverse(all(s1));
        reverse(all(s2));
        string res = sum();
        //reverse(all(res));
        //cout<<res<<endl;
        int n = res.size();
        int st = 0;
        for(int i = 0 ; i < n && res[i] == '0' ; ++i)
            ++st;
        for(int i = st ; i < n; ++i)
            printf("%c" , res[i]);
        blank;
    }



return 0;
}
