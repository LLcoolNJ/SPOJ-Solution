mod = 1298074214633706835075030044377087
def modPow(a,b):
    s = 1
    pw = a
    while b>0:
        if b&1:
            s = (s*pw)%mod
        pw = (pw*pw)%mod
        b >>= 1
    return (s-1)%mod

for _ in range(int(raw_input())):
    n = int(raw_input())
    print modPow(2,n+1)
        