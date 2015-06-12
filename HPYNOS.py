import sys
inp = sys.stdin.readline

def getLine():
    return inp().strip()

def getList():
    return map(int,inp().strip().split())
    
def getInt():
    return int(inp().strip())

n = getLine()
li = set()
cnt = 0
while True:
    s = 0
    for i in n:
        s += int(i)**2
    cnt += 1
    if s == 1:
        print cnt
        exit(0)
    else:
        if s in li:
            print -1
            exit(0)
        li.add(s)
        n = str(s)