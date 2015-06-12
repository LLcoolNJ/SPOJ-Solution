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


int main(){
    char s[5005];
    ULL val[5005];
    while(1){
        scanf("%s",&s);
        if(s[0] == '0')
            break;
        memset(val,0, sizeof val);
        val[0] = 1;
        int n = strlen(s);
        for(int i=1;i<=n-1;i++){
            int v = (s[i-1] - '0')*10 + (s[i] - '0');
            if(s[i] - '0')
                val[i] = val[i-1];
            if(v >= 10 && v <= 26){
                if(i-2 < 0)
                    val[i] += val[0];
                else
                    val[i] += val[i-2];
            }
        }
        printf("%llu\n",val[n-1]);
    }
	return 0;
}

