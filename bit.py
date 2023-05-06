class BIT():
    def __init__(self, A):
        self.N = len(A)
        self.A, self.S = A[:], [0] * (self.N + 1)
        for i in range(self.N):
            k = i + 1
            while k <= self.N:
                self.S[k] += self.A[i]; k = self.next(k)

    def update(self, i, x):
        diff, self.A[i] = x - self.A[i], x
        i += 1
        while i <= self.N:
            self.S[i] += diff; i = self.next(i)

    def query(self, i):
        t = 0
        while i:
            t += self.S[i]; i = self.prev(i)
        return t

    sum = lambda self, i, j: self.query(j + 1) - self.query(i)
    prev = lambda self, i: i - (i & -i)
    next = lambda self, i: i + (i & -i)

A = [1,2,3,4,5,6,7,8,9,10]
#    0 1 2 3 4 5 6 7 8 9
bit = BIT(A)
print(bit.sum(0, 4))  # A[0..4] = 15 = 1 + 2 + 3 + 4 + 5
print(bit.sum(0, 9))  # A[0..9] = 55 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
