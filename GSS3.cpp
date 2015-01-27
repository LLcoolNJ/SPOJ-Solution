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

/*Define SegmentTreeNode*/
struct SegmentTreeNode{
    int prefixMaxSum, suffixMaxSum, maxSum, sum;

    void assignLeaf(int value){
        prefixMaxSum = suffixMaxSum = maxSum = sum = value;
    }

    void merge(SegmentTreeNode& left, SegmentTreeNode& right){
        sum = left.sum + right.sum;
        prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
        suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
        maxSum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum, max(right.maxSum, left.suffixMaxSum + right.prefixMaxSum))));
    }
    int getValue(){
        return maxSum;
    }
};



template<class T, class V>
class SegmentTree{
    SegmentTreeNode *nodes;
    int N;
public:
    SegmentTree(T arr[], int N){
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr,1,0,N-1);
    }
    ~SegmentTree(){
        delete[] nodes;
    }

    V getValue(int lo, int hi){
        SegmentTreeNode result = getValue(1,0,N-1,lo,hi);
        return result.getValue();
    }
    void update(int index, T value){
        update(1,0,N-1,index,value);
    }
private:
    void buildTree(T arr[], int stIndex, int lo, int hi){
        if(lo == hi){
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }
        int left = 2*stIndex, right = left + 1, mid = (lo+hi)/2;
        buildTree(arr,left,lo,mid);
        buildTree(arr,right,mid+1,hi);
        nodes[stIndex].merge(nodes[left],nodes[right]);
    }
    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi){
        if(left == lo && right == hi)
            return nodes[stIndex];
        int mid = (left + right)/2;
        if(lo > mid)
            return getValue(2*stIndex+1, mid+1, right, lo, hi);
        if(hi <= mid)
            return getValue(2*stIndex, left, mid, lo, hi);
        SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
        SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
        SegmentTreeNode result;
        result.merge(leftResult,rightResult);
        return result;
    }
    int getSegmentTreeSize(int N){
        int size = 1;
        for(;size < N;size <<= 1);
        return size << 1;
    }
    void update(int stIndex, int lo, int hi, int index, T value){
        if(lo == hi){
            nodes[stIndex].assignLeaf(value);
            return;
        }
        int left = 2*stIndex, right = left + 1, mid = (lo+hi)/2;
        if(index <= mid)
            update(left, lo, mid, index, value);
        else
            update(right, mid+1, hi, index, value);
        nodes[stIndex].merge(nodes[left],nodes[right]);
    }
};


int main(){
    int N, i, A[50000], Q, L, R, C;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    SegmentTree<int,int> st(A,N);
    scanf("%d",&Q);
    for(i=0;i<Q;i++){
        scanf("%d",&C);
        if(C == 0){
            scanf("%d %d",&L,&R);
            st.update(L-1,R);
        }else if(C == 1){
            scanf("%d %d",&L,&R);
            printf("%d\n",st.getValue(L-1,R-1));
        }
    }
	return 0;
}

