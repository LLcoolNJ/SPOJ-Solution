from collections import deque
a = deque()
l = 0
while True:
    w = input()
    if w == -1:
        a.rotate(l/2)
        if l%2 == 0:
            if a[0] > a[-1]:
                print a.pop()
                a.rotate(-l/2)
            else:
                print a.popleft()
                a.rotate(l/2)
        else:
            print a.pop()
            a.rotate(l/2)
        l -= 1
    elif w == 0:
        break
    else:
        a.append(w)
        l += 1