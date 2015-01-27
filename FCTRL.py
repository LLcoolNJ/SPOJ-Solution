import sys
inp = sys.stdin.readlines()
def cntZ(n):
    s = 0
    d = 5
    while True:
        p = n/d
        if p == 0:break
        s += p
        d *= 5
    return s
for i in xrange(1,int(inp[0])+1):
    print cntZ(int(inp[i]))
