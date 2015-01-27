import sys
from math import sin
inp = sys.stdin.readlines()

def fun(x,a,b,c):
    # print a*x + b*sin(x) - c
    if a*x + b*sin(x) - c >=0:
        return True
    return False


def binS(a,b,c):
    lo,hi = 0,1000000
    mn = 1000000
    while lo < hi:
        mid = (lo+hi)/2.0
        # print lo,mid,hi,fun(mid,a)
        if not fun(mid,a,b,c):
            lo = mid
        else:
            hi = mid
            if abs(mn-mid) < 0.0000001:
                return round(mn,6)
            mn = mid
    return mn
for i in xrange(1,int(inp[0])+1):
    a,b,c = map(int,inp[i].split())
    print binS(a,b,c)