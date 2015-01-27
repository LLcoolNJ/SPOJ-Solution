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
LL v[1000000];
LL n,k;

LL fun(LL val){
    LL s = 0;
    for(LL i=0;i<n;i++){
        if(v[i]-val>0){
            s += v[i]-val;
        }else{
            return s;
        }
    }
    return s;
}

LL binSer(LL lo, LL hi){
    LL mid,f,mn = 0;
    while(lo <= hi){
        mid = (lo+hi)/2;
        f = fun(mid);
        //printf("%d %d %d %d %d\n",lo,mid,hi,f,mn);
        if(f == k){
            return mid;
        }else if(f > k){
            lo = mid+1;
            mn = max(mn,mid);
        }else{
            hi = mid-1;
        }
    }
    return mn;
}


int main(){
    //int val=0;
    scanf("%lld %lld",&n,&k);
    LL i;
    for(i=0;i<n;i++){
        scanf("%lld",&v[i]);
        //v.PB(val);
    }
    sort(v,v+n,greater<LL>());
    printf("%d\n",binSer(0,v[0]));
	return 0;
}


