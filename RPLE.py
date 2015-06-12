import sys
inp = sys.stdin.readline

def getLine():
    return inp().strip()

def getList():
    return map(int,inp().strip().split())
    
def getInt():
    return int(inp().strip())

for t in xrange(1,getInt()+1):
    fl = True
    n,r = getList()
    per = [False]*(1001)
    spy = [False]*(1001)
    mx = 0
    for _ in xrange(r):
        r1,r2 = getList()
        mx = max(mx,max(r1,r2))
        per[r2] = True
        spy[r1] = True
    for i in xrange(mx+1):
        if per[i] and spy[i]:
            fl = False
            break
    if fl:
        print "Scenario #%d: spying"%t
    else:
        print "Scenario #%d: spied"%t