from collections import Counter as Cnt
import sys
inp = sys.stdin.readline

def getLine():
    return inp().strip()

def getList():
    return map(int,inp().strip().split())
    
def getInt():
    return int(inp().strip())
    
for _ in xrange(getInt()):
    w = getLine()
    c = Cnt(w)
    mx = 0
    mxc = None
    cnt = 0
    # print c
    for i in c:
        if c[i] > mx and i != ' ':
            mx = c[i]
            mxc = i
            cnt = 1
        elif c[i] == mx:# and mxc != i:
            cnt += 1
        # print cnt,
    if cnt > 1:
        print 'NOT POSSIBLE'
        continue
    k = (ord(mxc) - ord('E') + 26)%26
    res = []
    for i in w:
        if 65 <= ord(i) <= 90:
            s = ord(i) - k
            if 65 <= s <= 90:
                res.append(chr(s))
            else:
                res.append(chr(s+26))
        else:
            res.append(i)
    print k,''.join(res)
    