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

int N,I;
vector<int> bug[2005];
int val[2005];

bool DFS(int start){
    bool res = true;
    for(int i=0;i<bug[start].size();i++){
        int top = bug[start][i];
        if(val[top] == val[start])
            return false;
        if(val[top] == 0){
            val[top] = -val[start];
            res &= DFS(top);
        }
    }
    return res;
}

int main(){
    int t,cs = 1;
    scanf("%d",&t);
    int ba,bb;
    while(cs <= t){
        printf("Scenario #%d:\n",cs);
        cs++;
        bool fl = true;
        scanf("%d %d",&N,&I);
        for(int i=0;i< N;i++){
            bug[i].clear();
            val[i] = 0;
        }
        for(int i=0;i<I;i++){
            scanf("%d %d",&ba,&bb);
            bug[ba].PB(bb);
            bug[bb].PB(ba);
        }
        bool res = true;
        for(int i=0;i<N;i++){
            if(val[i] == 0){
                val[i] = 1;
                res &= DFS(i);
            }
        }
        if(res)
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
        /*for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                printf("%d ",bug[i][j]);
            }
            printf("\n");
        }*/
    }
	return 0;
}

