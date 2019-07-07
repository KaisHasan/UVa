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




#define sz(v)     ((int)((v).size()))
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)

const int MAXLENGTH = 2 * 100 * 1000 + 9;
string str;  //the string we are building its suffix array
int suf[MAXLENGTH + 1];  // the sorted array of suffix indices
int group[MAXLENGTH + 1];  //In ith iteration: what is the group of the suffix index
int sorGroup[MAXLENGTH + 1 < 128 ? 128 : MAXLENGTH + 1];  //temp array to build grouping of ith iteration

int groupStart[MAXLENGTH + 1];  //the start index in the sorted array of the current group
int newSuf[MAXLENGTH + 1];  //temp array to store in it the new sorted array
int n;  //number of suffixes

void print_suffix(int suf_pos) {
  for (int j = suf_pos; j < n - 1; ++j)  // n-1 is string length NOT n
    cout << str[j];
}

void buildSuffixArray() {

  n = 0;
  memset(sorGroup, -1, (sizeof sorGroup[0]) * 128);

  //bucket sort on the first char of suffix
  for (n = 0; n - 1 < 0 || str[n - 1]; n++)
    //treat sorGroup as head of linked list and newSuf as next
    newSuf[n] = sorGroup[str[n]], sorGroup[str[n]] = n;

  int numGroup = -1, j = 0;
  for (int i = 0; i < 128; i++) {
    //compute the groups and groupStart and starting suf
    if (sorGroup[i] != -1) {
      groupStart[++numGroup] = j;
      int cur = sorGroup[i];  // cur = head

      while (cur != -1) {
        suf[j++] = cur;
        group[cur] = numGroup;
        cur = newSuf[cur];  // cur->next
      }
    }
  }

  sorGroup[0] = sorGroup[n - 1] = 0;  //assume that the first group index 0 for next iteration;
  newSuf[0] = suf[0];  //put the empty suffix to be the smallest suffix

  //loop until the number of groups=number of suffixes
  for (int h = 1; sorGroup[n - 1] != n - 1; h <<= 1) {
//    if (true) {  // For print
//      for (int i = 0; i < n; i++) {
//        print_suffix(suf[i]);
//
//        cout << "\t" << suf[i] << "\t" << group[suf[i]] << "\t" << groupStart[group[suf[i]]] << "\n";
//      }
//      cout << "\n";
//    }
    for (int i = 0; i < n; i++) {  //sort using 2h in the array newSuf
      int j = suf[i] - h;
      if (j < 0)
        continue;
      newSuf[groupStart[group[j]]++] = j;
    }
    for (int i = 1; i < n; i++) {  //compute the 2h group data given h group data
      bool newgroup = group[newSuf[i - 1]] < group[newSuf[i]] || (group[newSuf[i - 1]] == group[newSuf[i]] && group[newSuf[i - 1] + h] < group[newSuf[i] + h]);

      sorGroup[i] = sorGroup[i - 1] + newgroup;
      if (newgroup)
        groupStart[sorGroup[i]] = i;
    }
    for (int i = 0; i < n; i++) {  //copy the data
      suf[i] = newSuf[i];
      group[suf[i]] = sorGroup[i];
    }
  }
}


//LCP

int Rank[MAXLENGTH + 1];
int lcp[MAXLENGTH + 1];

void buildLcp() {
  //compute the rank of each suffix
  for (int i = 0; i - 1 < 0 || str[i - 1]; i++)
    Rank[suf[i]] = i;

  int c = 0;  // the length of lcp between i and j
  for (int i = 0; i - 1 < 0 || str[i - 1]; i++) {
    if (Rank[i]) {  //if i is not the first suffix in the sorted array
      int j = suf[Rank[i] - 1];  //find the element before i and name it j
      while (str[i + c] == str[j + c])
        c++;  //count the number of shared chars
    }
    lcp[Rank[i]] = c;  //store the result in lcp array
    if (c)
      c--;  //Decrement c by one because length of lcp of i+1 is c-1
  }
//  if (false) {
//    for (int i = 0; i < n; i++) {
//      print_suffix(suf[i]);
//      cout << "\t" << suf[i] << "\t" << Rank[i] << "\t" << lcp[i] << "\n";
//    }
//  }
}



pi tree[4*MAXLENGTH + 1];

pi _merge(pi a , pi b){
    return MP(min(a.first, b.first) , max(a.second , b.second));
}

void build(int p , int l , int r){
    if(l == r){
        tree[p] = MP(lcp[l],lcp[l]);
        return;
    }
    int md = (l + r)>>1;
    build(p * 2 , l , md );
    build(p * 2+ 1 , md + 1 , r);
    tree[p] = _merge(tree[p*2] , tree[p*2+1]);
}

pi qwr(int p , int l , int r , int st , int en){
    if(st == en)
        return MP(lcp[st],lcp[en]);
    if(st > en)
        return MP(0,0);
    if(l > en || r < st)
        return MP(inf , -inf);
    if(l >= st && r <= en)
        return tree[p];
    int md = (l + r)>>1;
    return _merge(qwr(p * 2 , l , md , st , en) , qwr(p*2+1 , md + 1 , r , st , en));
}

int color[MAXLENGTH + 1] , cnt[MAX];

int get_color(int x){
    return color[suf[x]];
}

vector<char> to_add;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
for(char c = 'A' ; c<= 'Z' ; ++c)
    to_add.pb(c);
to_add.pb('@');
to_add.pb('$');
to_add.pb('#');

    while(1){
        mem(color , 0);
        int n;
        sc(n);
        if(!n)
            break;
        if(cases)
            blank;
        ++cases;
        str.clear();
        cin>>str;
        color[0] = 1;
        int id = 0;
        for(int i = 1 ; i < n ; ++i ,id = (id+1)%(int)to_add.size()){
            string s;
            cin>>s;
            color[(int)str.size()] = 1;
            str += to_add[id] + s;
        }
//        if(str.find("ail") != -1 && str.find("cie") != -1 && str.find("edd") != -1){
//            pla;
//            printf("%s\n" , str.c_str());
//            pla;
//        }
        int SIZE = (int)str.size() + 1;
        for(int i = 1 ; i < SIZE ; ++i)
            color[i] += color[i-1];
        buildSuffixArray();
        buildLcp();
        build(1 , 0 , SIZE - 1);
//        for(int i = 0 ; i < SIZE ; ++i){
//            printf("c[%d] == %d\n" , i , get_color(i));
//        }
//        blank;
        int l = n - 1, r = n- 1;
        int mx = -1;
        int half = n / 2;
        vi res;
        int num = 0;
        res.clear();
        mem(cnt , 0);
        if(n == 1){
            printf("%s\n" , str.c_str());
            continue;
        }
        while(r < SIZE){
            while(r < SIZE && num <= half){
                cnt[get_color(r)]++;
                if(cnt[get_color(r)] == 1)
                    ++num;
                ++r;
//                printf("l == %d , r == %d\n" , l , r);
            }
            if(num > half){
                int mn = qwr(1 , 0 , SIZE - 1, l + 1 , r - 1).first;
//                printf("mn == %d , l == %d , r == %d\n" , mn , l , r);
                if(mn > mx){
                    res.clear();
                    mx = mn;
                    res.pb(suf[l]);
                }
                else if(mn == mx){
                    res.pb(suf[l]);
                }
            }
            while(l < r){
                if(l == SIZE)
                    break;
                cnt[get_color(l)]--;
                if(!cnt[get_color(l)])
                    --num;
                ++l;
//                printf("l == %d , r == %d\n" , l , r);
                if(num > half && l + 1 <= r - 1){
                    int mn = qwr(1 , 0 , SIZE - 1, l + 1 , r - 1).first;
//                    printf("mn == %d , l == %d , r == %d\n" , mn , l , r);
                    if(mn > mx){
                        res.clear();
                        mx = mn;
                        res.pb(suf[l]);
                    }
                    else if(mn == mx){
                        res.pb(suf[l]);
                    }
                }
                if(num <= half)
                    break;
            }
//            if(r == SIZE - 1)
//                break;
        }
        if(mx <= 0){
            printf("?\n");
            continue;
        }
        vector<string> v;
        v.clear();
        for(auto st : res){
            v.pb(str.substr(st , mx));
        }
        set<string> f;
        f.clear();
        f.insert(all(v));
//        printf("f size == %d\n" , (int)f.size());
//        printf("mx == %d\n" , mx);
        for(auto it : f){
            //if(it.find("@") == -1 && isalpha(it[0]))
                printf("%s\n" , it.c_str());
        }

    }



return 0;
}
