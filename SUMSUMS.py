import sys
inp = sys.stdin.readlines()
mod = 98765431
n,k = map(int,inp[0].split())
arr = map(int,inp[1:])
if n == 1:
    print 0
    sys.exit(0)
S = sum(arr)
p = 1
if k%2 == 0:
    p = -1
x = (pow(n-1,k,mod) + p +mod)%mod
# print x
y = pow(n,mod-2,mod)
x = (x*y)%mod
# print x
S = (x*S)%mod
a = [str((S + p*(-i) + mod)%mod) for i in arr]
print ' '.join(a)
# for i in arr:
    # print (S + p*(-i) + mod)%mod ,