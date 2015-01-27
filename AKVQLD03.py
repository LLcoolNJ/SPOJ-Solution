#Fenwick Tree
class FenwickTree:
    def __init__(self,n):
        self.maxVal = n
        self.tree = [0]*(n+1)
        '''for j in xrange(1,self.maxVal+1):
            i = (j&-j)
            # print i,j
            self.tree.append(sum(self.li[j-i:j]))'''
        # print self.li
        # print self.tree
    def update(self,ind,val):
        '''update(self,ind,val)
           add val at index ind'''
        while ind <= self.maxVal:
            self.tree[ind] += val
            ind += (ind&-ind)
    def read(self,ind):
        '''read(self,ind)
           read cm sum of index ind'''
        s = 0
        while ind > 0:
            s += self.tree[ind]
            ind -= (ind&-ind)
        return s
    def readSingle(self,ind):
        '''readSingle(self,ind)
           read exact value of ind'''
        s = self.tree[ind]
        if ind > 0:
            z = ind - (ind&-ind)
            ind -= 1
            while ind != z:
                s -= self.tree[ind]
                ind -= (ind&-ind)
        return s
    def scale(self,c):
        '''scale(self,c)
           scale all element by c'''
        for i in xrange(1,self.maxVal+1):
            self.tree[i] = self.tree[i]/c
n,m = map(int,raw_input().split())
ft = FenwickTree(n)
for _ in xrange(m):
    w = raw_input().split()
    if w[0] == 'add':
        ft.update(int(w[1]),int(w[2]))
    elif w[0] == 'find':
        print ft.read(int(w[2])) - ft.read(int(w[1])-1)