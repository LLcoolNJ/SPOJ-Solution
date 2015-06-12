import sys
sys.setrecursionlimit = 400001

inp = sys.stdin.readline

def getLine():
    return inp().strip()

def getList():
    return map(int,inp().strip().split())
    
def getInt():
    return int(inp().strip())

def jos(n,k):
    ans = 1
    for i in xrange(2,n+1):
        ans = (ans + n-i)%i + 1
    return ans
    # if n == 1:
        # return 1
    # else:
        # return (jos(n-1,k+1) + k-1 )%n +1 
    
for _ in xrange(getInt()):
    n = getInt()
    print jos(n,1)