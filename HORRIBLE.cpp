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
LL B1[100005],B2[100005];
int N;

void init(){
    memset(B1,0,(N+1)*sizeof(LL));
    memset(B2,0,(N+1)*sizeof(LL));
}
LL read(LL *ft,int ind){
    LL s = 0;
    for(;ind>0;ind -= opr(ind))
        s += ft[ind];
    return s;
}
LL readRes(int ind){
    return read(B1,ind)*ind - read(B2,ind);
}
LL readRange(int L, int R){
    return (readRes(R) - readRes(L-1));
}

void update(LL *ft,int ind, LL val){
    for(;ind<=N;ind += opr(ind))
        ft[ind] += val;
}

void updateRange(int l, int r, LL v){
    update(B1,l,v);
    update(B1,r+1,-v);
    update(B2,l,v*(l-1));
    update(B2,r+1,-v*r);
}

int main(){
    int t,Q,ind,L,R,V,type;
    scanf("%d",&t);
    //printf("%d\n",t);
    while(t--){
        scanf("%d %d",&N,&Q);
        init();
        for(int i=0;i<Q;i++){
            scanf("%d",&type);
            if(type == 0){
                scanf("%d %d %d",&L,&R,&V);
                updateRange(L,R,V);
            }else if(type == 1){
                scanf("%d %d",&L,&R);
                printf("%lld\n",readRange(L,R));
            }
        }
    }
	return 0;
}


