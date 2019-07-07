#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double dd;

bool check(char c1 , char c2){
     if(c1 == c2)
        return 0;
     return 1;
}

int main(void){
   string s1;
   string s2;
   cin>>s1>>s2;
   int n = s1.size();
   string s3;
   for(int i = 0 ; i < n ; ++i){
        if(check(s1[i] , s2[i]))
            s3.push_back('1');
        else
            s3.push_back('0');
   }

   cout<<s3;

}
