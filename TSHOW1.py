import sys
from collections import deque
inp = sys.stdin.readlines()
def AB_label(n):
    letters = '56'
    result = deque()
    while n > 0:
        n -= 1 
        char = letters[n % 2]
        n = n / 2
        result.appendleft(char)
    return ''.join(result)

for i in xrange(1,int(inp[0])+1):
    print AB_label(int(inp[i]))