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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int DirectPar[MAX];
int par[MAX];
int n;

void initi(){
    for(int i = 0 ; i < n ; ++i)
        par[i] = DirectPar[i] = i;
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}

int Dparent(int v){
    if(DirectPar[v] == v)
        return v;
    printf("DirectPar[%d] == %d\n" ,v, DirectPar[v]);
    return Dparent(DirectPar[v]);
}

bool _merge(int u , int v){
    int paru = parent(u) , parv = parent(v);
    if(paru == parv)
        return 0;
    return 1;
}

void re(int u , int depth){
    if(DirectPar[u] == u){
        if(depth > 0)
            par[u] = u;
        return;
    }
    re(DirectPar[u] , depth + 1);
    DirectPar[u] = u;
    if(depth > 0){
        par[u] = u;
    }
}

void disJoint(int a){
    for(int i = 0 ; i < n ; ++i){
        if(DirectPar[i] == a){
            DirectPar[i] = i;
            return;
        }
    }
}

void join_to_A(int a , int u){
    if(DirectPar[u] == u){
        par[u] = a;
        return;
    }
    par[u] = a;
    join_to_A(a , DirectPar[u]);
}

void move_A_onto_B(int a , int b){
    if(!_merge(a , b))
        return;
    re(a , 0);re(b , 0);
    disJoint(a);
    DirectPar[b] = a;
    par[a] = parent(b);
}

void move_A_over_B(int a , int b){
    if(!_merge(a , b))
        return;
    re(a , 0);
    disJoint(a);
    DirectPar[Dparent(b)] = a;
    par[a] = parent(b);
}

void pile_A_onto_B(int a , int b){
    if(!_merge(a , b))
        return;
    re(b , 0);
    disJoint(a);
    join_to_A(a , a);
    DirectPar[b] = a;
    par[a] = parent(b);
}

// the bug is here ,,, Dparent function recurse forever because of cycle in Dpar
void pile_A_over_B(int a , int b){
    if(!_merge(a , b))
        return;
    printf("a == %d  , b == %d\n" , a , b);
    disJoint(a);
    join_to_A(a , a);
    printf("after dis\n");
    printf("Dparent(b) == %d\n" , Dparent(b));
    DirectPar[Dparent(b)] = a;
    printf("after Dpar\n");
    par[a] = parent(b);
    printf("after par\n");
}


void print(int u){
    if(DirectPar[u] == u){
        printf(" %d" , u);
        return;
    }
    printf(" %d" , u);
    print(DirectPar[u]);
}


int main(){
//freopen("output.txt" , "w" , stdout);
freopen("input.txt" , "r" , stdin);

    sc(n);
    initi();
    while(1){
        char s[10];
        scanf("%s" , s);
        if(!strcmp(s,"quit"))
            break;
        int a;
        sc(a);
        char t[10];
        scanf("%s" , t);
        int b;
        sc(b);
        if(!strcmp(s , "move")){
            if(!strcmp(t,"onto")){
                printf("m %d onto %d\n" ,a , b);
                move_A_onto_B(a , b);
            }
            else{
                printf("m  %d over %d \n", a , b);
                move_A_over_B(a , b);
            }
        }
        else{
            if(!strcmp(t,"onto")){
                printf("p %d onto %d\n" , a , b);
                pile_A_onto_B(a , b);
            }
            else{
                printf("p %d over %d\n" , a , b);
                pile_A_over_B(a , b);
                printf("finished!!!\n");
            }
        }
    }
    for(int i = 0 ; i < n ; ++i){
        printf("%d:" , i);
        if(par[i] == i){
            print(i);
        }
        blank;
    }


return 0;
}
