import sys
inp = sys.stdin.readlines()
mod = int(1e9 + 7)
def mul(A,B):
    a,b,c = A
    d,e,f = B
    return ((a*d)%mod + (b*e)%mod)%mod,((a*e)%mod + (b*f)%mod)%mod,((b*e)%mod+(c*f)%mod)%mod
def pow(A,n):
    if n == 1: return A
    if n&1 == 0:return pow(mul(A,A),n//2)
    else:return mul(A,pow(mul(A,A),(n-1)//2))
def fib(n):
    if n<2:return n
    return pow((1,1,0),n-1)[0]

for i in xrange(1,int(inp[0])+1):
    l,r = map(int,inp[i].split())
    # print fib(l)
    # print l,r
    print (fib(r+2) - fib(l+1) + mod)%mod