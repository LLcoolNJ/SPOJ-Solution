import sys
from math import floor,log,pi
inp = sys.stdin.readlines()

def cntD(n):
    return int(floor((log(2*pi*n)/2 + n*(log(n) - 1))/log(10)) +1)
arr = map(int,inp[1:])
for i in xrange(int(inp[0])):
    if arr[i] in [0,1,2,3]:
        print 1
        continue
    print cntD(arr[i])