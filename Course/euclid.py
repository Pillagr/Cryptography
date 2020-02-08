class Euclid:
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.q = a//b
        self.r = a - (self.b*self.q)
    def __repr__(self):
        return "{} = {} * {} + {}".format(self.a, self.b, self.q, self.r)

    #@classmethod
    def next(self):
        a = self.b
        b = self.r
        return self.__class__(a,b)

    def gcd(self, p=False):
        if self.r == 0:
            return b
        funcs = [self]
        while(True):
            nxt = self.next()
            funcs.append(nxt)
            if self.r == 0:
                return nxt.r, funcs
            if nxt.r == 0:
                return self.r, funcs
            self = nxt.next()
            funcs.append(self)
            if p:
                print(nxt)
                print(self)
                
            
            
        


if __name__ == "__main__":
    a, b = 8625, 2044
    s = Euclid(a,b) 
    s.gcd(True)

    pass