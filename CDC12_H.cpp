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

#define MAXN 100005
#define MAX 1100000

//int arr[MAXN];
LL tree[MAX];
LL lazy[MAX];

/*void build(int node, int a, int b){
    if(a>b)return;
    if(a == b){
        tree[node] = arr[a];
        return;
    }
    build(node*2,a,(a+b)/2);
    build(node*2+1,(a+b)/2 +1,b);
    tree[node] = tree[node*2] + tree[node*2+1];
}*/

void update(int node, int a, int b, int i, int j){
    if(lazy[node] != 0){
        tree[node] += (b - a + 1)*lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node] ;
            lazy[node*2+1] += lazy[node] ;
        }
        lazy[node] = 0;
    }
    if(a > b || a > j || b < i)
        return;
    if(a >= i && b <= j){
        tree[node] += (b - a + 1);
        if(a != b){
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return;
    }
    update(node*2,a,(a+b)/2,i,j);
    update(node*2+1,(a+b)/2 + 1,b,i,j);
    tree[node] = tree[node*2] + tree[node*2+1];
}

LL query(int node, int a, int b, int i, int j){
    if(a > b || a > j || b < i)return 0;
    if(lazy[node] != 0){
        tree[node] += (b - a + 1)*lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node] ;
            lazy[node*2+1] += lazy[node] ;
        }
        lazy[node] = 0;
    }
    if(a >= i && b <= j)
        return tree[node];
    int q1 = query(node*2,a,(a+b)/2,i,j);
    int q2 = query(node*2+1,(a+b)/2+1,b,i,j);
    return q1+q2;
}


int main(){
    int t,cc = 1;
    scanf("%d",&t);
    while(cc <= t){
        printf("Scenario #%d:\n",cc);
        cc++;
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        int n,m;
        scanf("%d %d",&n,&m);
        int l, r;
        char cs[20];
        for(int i=0;i<m;i++){
            scanf("%s %d %d",cs,&l,&r);
            //printf("%s %d %d\n",cs,l,r);
            if(cs[0] == 'm'){
                update(1,0,n-1,l-1,r-1);
                printf("OK\n");
            }else if(cs[0] == 'a'){
                printf("%lld\n",query(1,0,n-1,l-1,r-1));
            }
            /*for(int j=1;j<8;j++)
                printf("Tree %d: %d %d\n",j,tree[j],lazy[j]);
            printf("\n");*/
        }
    }
	return 0;
}

