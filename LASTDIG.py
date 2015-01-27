def lastDigit(a,b):
    d = {}
    d[2] = [6,2,4,8]
    d[3] = [1,3,9,7]
    d[4] = [6,4,6,4]
    d[7] = [1,7,9,3]
    d[8] = [6,8,4,2]
    d[9] = [1,9,1,9]
    if b == 0:return 1
    elif a in [1,5,6,0]:
        return a
    else:
        return d[a][b%4]
for _ in xrange(int(raw_input())):
    a,b = map(int,raw_input().split())
    print lastDigit(a%10,b)