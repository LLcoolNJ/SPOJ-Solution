for _ in xrange(input()):
    a = input()
    if a&1:
        print a
    else:
        x = bin(a)[2:]
        print int('0b'+x[-1::-1],2)