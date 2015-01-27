import sys
inp = sys.stdin.readlines()
mod = 1000007

for i in xrange(1,int(inp[0])+1):
    n = int(inp[i])
    if n%2 == 0:
        S = ((n/2)*(((3*n)%mod+1)%mod))%mod
    else:
        S = (n*(((3*n+1)/2)%mod))%mod
    print S