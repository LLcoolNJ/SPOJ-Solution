import sys
inp = sys.stdin.readlines()
i = 1
def fun(x,c,arr):
    proc = 1
    last = arr[0]
    for i in xrange(1,len(arr)):
        if arr[i] - last >= x:
            proc += 1
            last = arr[i]
        if proc == c:
            return 1
    return 0
def binS(c,arr):
    lo,hi = 0,arr[-1]
    mx = -1
    while lo < hi:
        mid = (lo+hi)/2
        if fun(mid,c,arr) == 1:
            mx = max(mx,mid)
            lo = mid+1
        else:
            hi = int(mid)
        # print lo,mid,hi
    return mx

for _ in xrange(int(inp[0])):
    n,c = map(int,inp[i].split())
    i += 1
    arr = sorted(map(int,inp[i:i+n]))
    i += n
    print binS(c,arr)