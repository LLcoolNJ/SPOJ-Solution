import sys
from math import log,pi
inp = sys.stdin.readlines()

def fun(n,a):
    # print n*log(n) - n +1/float(6) * log(n*(1 +4*n*(1+2*n))) + log(pi)/float(2), n*log(a)
    if (n*log(n) - n +1/float(6) * log(n*(1 +4*n*(1+2*n))) + log(pi)/float(2)) > n*log(a):
        return True
    return False

def binS(a):
    lo,hi = 4,2718275
    mn = 2718275
    while lo < hi:
        mid = (lo+hi)/2
        # print lo,mid,hi,fun(mid,a)
        if not fun(mid,a):
            lo = mid +1
        else:
            hi = mid
            mn = min(mn,mid)
    return mn
for i in xrange(1,int(inp[0])+1):
    print binS(int(inp[i]))