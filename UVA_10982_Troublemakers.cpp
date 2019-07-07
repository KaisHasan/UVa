/* 13969931	10982	Troublemakers	Accepted	C++	0.016	2014-07-31 07:18:01 */
/* Template By Shark */
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 100
#define MAX_M 5000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++){
		int n, m;
		int G[MAX_N + 1] = { 0 };
		pair<int, int> P[MAX_M + 1];
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d", &P[i].first, &P[i].second);
		for (int i = 1; i <= n; i++){
			int count[2] = { 0 };
			for (int j = 0; j < m; j++){
				if (P[j].first <= i && P[j].second <= i && (P[j].first == i || P[j].second == i)){
					if (P[j].first == i)
						count[G[P[j].second]]++;
					else
						count[G[P[j].first]]++;
				}
			}
			if (count[0] > count[1])
				G[i] = 1;
		}
		vector<int> T;
		for (int i = 1; i <= n; i++)
			if (G[i] == 1)
				T.push_back(i);
		printf("Case #%d: %d\n", c, T.size());
		for (int i = 0; i < T.size(); i++){
			if (i != 0)	putchar(' ');
			printf("%d", T[i]);
		}
		putchar('\n');
	}
	return 0;
}
