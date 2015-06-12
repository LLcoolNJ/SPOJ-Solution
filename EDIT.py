import sys
inp = sys.stdin.readlines()
def solve(s):
    rs1 = 0
    rs2 = 0
    l = 0
    cnt = 1
    for i in xrange(len(s)-1):
        if not(s[i].isupper() == s[i+1].isupper() or s[i].islower() == s[i+1].islower()):
           cnt += 1 
        else:
            if l%2 == 0:
                rs1 += cnt
            else:
                rs2 += cnt
            l += 1
            cnt = 1
    if l%2 == 0:
        rs1 += cnt
    else:
        rs2 += cnt
    # print rs1,rs2
    return min(rs1,rs2)

for i in inp:
    s = i.strip()
    print solve(s)