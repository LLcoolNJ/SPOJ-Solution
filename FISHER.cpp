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

#define MAX 55

int N,tim;
int tTime[MAX][MAX];
int toll[MAX][MAX];
int cost[1001][MAX];

int main(){
    while(true){
        scanf("%d %d",&N,&tim);
        if(N == 0 && tim == 0)
            break;
        //memset(cost, inf, sizeof cost);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&tTime[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&toll[i][j]);
            }
        }
        for (int t = 0; t <= tim; t++){
			for (int i = 0; i < N; i++){
				cost[t][i] = inf;
			}
        }
        cost[0][0] = 0;
        int resC = inf, resT = inf;
        for(int t=0;t<=tim;t++){
            for(int i=0;i<N;i++){
                if(cost[t][i] >= inf)
                    continue;
                if(t < tim)
                    cost[t+1][i] = min(cost[t+1][i],cost[t][i]);
                for(int j=0;j<N;j++){
                    if(t + tTime[i][j] <= tim){
                        int ts = t + tTime[i][j];
                        cost[ts][j] = min(cost[ts][j], cost[t][i] + toll[i][j]);
                    }
                }
            }
            if(cost[t][N-1] < resC){
                resC = cost[t][N-1];
                resT = t;
            }
        }
        printf("%d %d\n",resC,resT);
    }

	return 0;
}

