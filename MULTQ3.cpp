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
#define MAX 262144

//int arr[MAXN];

struct Tree{
    int rem[3];
    int lazy;
}tree[MAX] = {{0},0};

void build(int node, int a, int b){
    if(a>b)return;
    if(a == b){
        //int c = arr[a]%3;
        tree[node].rem[0]++;
        return;
    }
    build(node*2,a,(a+b)/2);
    build(node*2+1,(a+b)/2 +1,b);
    for(int i=0;i<3;i++)
        tree[node].rem[i] = tree[node*2].rem[i] + tree[node*2+1].rem[i];
}

void update(int node, int a, int b, int i, int j){
    if(tree[node].lazy != 0){
        int temp;
        switch(tree[node].lazy%3){
        case 1:
            temp = tree[node].rem[2];
            tree[node].rem[2] = tree[node].rem[1];
            tree[node].rem[1] = tree[node].rem[0];
            tree[node].rem[0] = temp;
            break;
        case 2:
            temp = tree[node].rem[2];
            tree[node].rem[2] = tree[node].rem[0];
            tree[node].rem[0] = tree[node].rem[1];
            tree[node].rem[1] = temp;
            break;
        }
        if(a != b){
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
    if(a > b || a > j || b < i)
        return;
    if(a >= i && b <= j){
        int temp = tree[node].rem[2];
        tree[node].rem[2] = tree[node].rem[1];
        tree[node].rem[1] = tree[node].rem[0];
        tree[node].rem[0] = temp;
        if(a != b){
            tree[node*2].lazy++;
            tree[node*2+1].lazy++;
        }
        return;
    }
    update(node*2,a,(a+b)/2,i,j);
    update(node*2+1,(a+b)/2 + 1,b,i,j);
    for(int i=0;i<3;i++)
        tree[node].rem[i] = tree[node*2].rem[i] + tree[node*2+1].rem[i];
}

int query(int node, int a, int b, int i, int j){
    if(a > b || a > j || b < i)return 0;
    if(tree[node].lazy != 0){
        int temp;
        switch(tree[node].lazy%3){
        case 1:
            temp = tree[node].rem[2];
            tree[node].rem[2] = tree[node].rem[1];
            tree[node].rem[1] = tree[node].rem[0];
            tree[node].rem[0] = temp;
            break;
        case 2:
            temp = tree[node].rem[2];
            tree[node].rem[2] = tree[node].rem[0];
            tree[node].rem[0] = tree[node].rem[1];
            tree[node].rem[1] = temp;
            break;
        }
        if(a != b){
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
    if(a >= i && b <= j)
        return tree[node].rem[0];
    int q1 = query(node*2,a,(a+b)/2,i,j);
    int q2 = query(node*2+1,(a+b)/2+1,b,i,j);
    return q1+q2;
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int c, l, r;
    build(1,0,n-1);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&c,&l,&r);
        if(c == 0){
            update(1,0,n-1,l,r);
        }else if(c == 1){
            printf("%d\n",query(1,0,n-1,l,r));
        }
        /*for(int j=1;j<8;j++){
            printf("Tree %d: %d %d %d %d\n",j,tree[j].rem[0],tree[j].rem[1],tree[j].rem[2],tree[j].lazy);
        }
        printf("\n");*/
    }
	return 0;
}

