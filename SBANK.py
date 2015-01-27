import sys
# from heapq import heappush as push, heappop as pop
from collections import defaultdict as dikt
inp = sys.stdin.readlines()
j = 1
for _ in xrange(int(inp[0])):
    # h = []
    d = dikt(int)
    for i in xrange(int(inp[j])):
        j += 1
        d[inp[j].strip()] += 1
        # push(h,inp[j].strip())
    j += 2
    for i in sorted(d):
        print i,d[i]
    print 
    