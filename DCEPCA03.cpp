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
typedef vector<long> VL;
typedef vector<LL> VLL;
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

#define N 10005
#define MAXN 1000000
int phi[MAXN + 1], prime[MAXN/10], sz=0;
vector<bool> mark(MAXN + 1);

int main(){
   phi[1] = 1;
   for (int i = 2; i <= MAXN; i++ ){
        if(!mark[i]){
            phi[i] = i-1;
            prime[sz++]= i;
        }
        for (int j=0; j<sz && prime[j]*i <= MAXN; j++ ){
            mark[prime[j]*i]=1;
            if(i%prime[j]==0){
                int ll = 0;int xx = i;
                while(xx%prime[j]==0)
                {
                               xx/=prime[j];
                               ll++;
                           }
                int mm = 1;
                for(int k=0;k<ll;k++)mm*=prime[j];
                phi[i*prime[j]] = phi[xx]*mm*(prime[j]-1);
                break;
            }
            else phi[i*prime[j]] = phi[i]*(prime[j]-1 );
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        LL s = 0,res = 0;
        for(int i=1;i<=n;i++)
            s += phi[i];
        for(int i=1;i<=n;i++)
            res += phi[i]*s;
        printf("%lld\n",res);
    }
    return 0;
}
