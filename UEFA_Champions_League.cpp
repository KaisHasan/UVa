#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double eps = 0.0000001;

int a , b , c , d;

int main(){

    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(a + c > b + d)
            cout<<1<<endl;
        else if(b + d > a + c)
            cout<<2<<endl;
        else if(b > c)
            cout<<2<<endl;
        else if(c > b)
            cout<<1<<endl;
        else
            cout<<-1<<endl;
    }




return 0;
}
