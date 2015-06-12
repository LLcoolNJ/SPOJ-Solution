import sys
inp = sys.stdin.readlines()
i = 1
for _ in xrange(int(inp[0])):
    w = int(inp[i])
    i += 1
    b = bin(w)[2:]