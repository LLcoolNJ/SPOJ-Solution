#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <complex>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,b) for(int i=a-1;i>=b;i--)
#define rev(i,n) REV(i,n,0)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define GI ({ int x; scanf("%d",&x); x; })
#define GLL ({ LL x; scanf("%lld",&x); x; })
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define inf (int)(1e9)
#define linf (LL)(1e18)
#define eps (double)(1e-9)
#define leps (LD)(1e-18)
#define PI (double)(3.141592653589793238)

ULL powbits[33] = {0};

void init_powbits(){
	for (int i=1; i<33; i++) {
		powbits[i] = (ULL)i << (i-1);
	}
}

int fls(UL n){
	int ret = 0;
	while (n) {
		ret++;
		n >>= 1;
	}
	return ret;
}

ULL countbitu(UL n){
	if (n == 0)
		return 0;

	int h = fls(n) - 1;
	int over = n - (1 << h);

	return powbits[h] + over + countbitu(over) + 1;
}

ULL countbits(LL n){
	if (n >= 0)
		return countbitu(n);
	
	LL nn = -n;

	return nn * 32 - countbitu(nn - 1);
}

ULL subbits(long a, long b){
	if (a == 0 || b == 0)
		return countbits(a) + countbits(b);

	if (a < 0 && b > 0)
		return countbits(a) + countbits(b);

	if (a < 0 && b < 0)
		return countbits(a) - countbits(b+1);

	if (a > 0 && b > 0)
		return countbits(b) - countbits(a-1);

	return 0;
}

int main(){
	init_powbits();

	int t;
	cin >> t;
	
	while (t--) {
		LL a, b;
		cin >> a >> b;
		cout << subbits(a, b) << endl;
	}

	return 0;
}
