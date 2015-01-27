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
#define opr(n) (n&(-n))
LL ft[10005];
int N;

void init(){
    memset(ft,0,(N+1)*sizeof(LL));
}
LL read(int ind){
    LL s = 0;
    for(;ind>0;ind -= opr(ind))
        s += ft[ind];
    return s;
}

void update(int ind, int val){
    for(;ind<=N;ind += opr(ind))
        ft[ind] += val;
}

void updateRange(int l, int r, int v){
    update(l,v);
    update(r+1,-v);
}

int main(){
    int t,U,Q,ind,L,R,V;
    scanf("%d",&t);
    //printf("%d\n",t);
    while(t--){
        scanf("%d %d",&N,&U);
        init();
        for(int i=0;i<U;i++){
            scanf("%d %d %d",&L,&R,&V);
            updateRange(L+1,R+1,V);
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d",&ind);
            printf("%d\n",read(ind+1));
        }
    }
	return 0;
}


