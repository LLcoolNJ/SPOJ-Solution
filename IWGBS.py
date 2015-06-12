n = input()
res = [0,2,3]
if n >= 3:
    for i in xrange(3,n+1):
        res.append(res[-1] + res[-2])
# print res
print res[n]