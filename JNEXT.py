import sys
inp = sys.stdin.readlines()
def nextPer(arr):
    i = len(arr) - 1
    while i > 0 and arr[i - 1] >= arr[i]:
        i -= 1
    if i <= 0:
        print -1
        return False
    j = len(arr) - 1
    while arr[j] <= arr[i - 1]:
        j -= 1
    arr[i - 1], arr[j] = arr[j], arr[i - 1]
    arr[i : ] = arr[len(arr) - 1 : i - 1 : -1]
    print ''.join(arr)
    return True
i = 1
for _ in xrange(int(inp[0])):
    n = int(inp[i])
    i += 1
    arr = inp[i].split()
    i += 1
    nextPer(arr)