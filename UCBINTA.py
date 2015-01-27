n = int(raw_input())
a = []
for _ in xrange(n):
    a.append(sum(map(int,raw_input().split())))
s = sum(a)/((n-1)*2)
for i in a:
    if n == 2:
        print i/2,
    else:print (i-s)/(n-2),
