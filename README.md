# Binary Index Tree (BIT)

Prefix sums with `query` + `update` in `O(logN)` time

## Naive Prefix Sums

`query` + `update` in O(N) time via two possibilities:

1. `query` in `O(1)` time + `update` in `O(N)` time
2. `query` in `O(N)` time + `update` in `O(1)` time

# Implementations

*Kotlin*
```java
class BIT(A: IntArray) {
    var A: IntArray
    var S: IntArray
    var N: Int
    var prev = { i: Int -> i - (i and -i) }
    var next = { i: Int -> i + (i and -i) }
    init {
        this.A = A
        N = A.size
        S = IntArray(N + 1) { 0 }
        for (i in 0 until N) {
            var k = i + 1
            while (k <= N) {
                S[k] += A[i]; k = next(k)
            }
        }
    }
    fun update(i: Int, x: Int) {
        var diff = x - A[i]; A[i] = x
        var k = i + 1
        while (k <= N) {
            S[k] += diff; k = next(k)
        }
    }
    fun query(i: Int): Int { return if (0 < i) S[i] + query(prev(i)) else 0 }
    var sum = { i: Int, j: Int -> query(j + 1) - query(i) }
}
```

*Javascript*
```javascript
class BIT {
    constructor(A) {
        this.A = [...A];
        this.N = this.A.length;
        this.S = Array(this.N + 1).fill(0);
        for (let i = 0; i < this.N; ++i)
            for (let k = i + 1; k <= this.N; k = this.next(k))
                this.S[k] += this.A[i];
    }
    update = (i, x) => {
        let diff = x - this.A[i]; this.A[i] = x;
        for (let k = i + 1; k <= this.N; k = this.next(k))
            this.S[k] += diff;
    }
    sum = (i, j) => this.query(j + 1) - this.query(i);
    query = i => i ? this.S[i] + this.query(this.prev(i)) : 0;
    prev = i => i - (i & -i);
    next = i => i + (i & -i);
}

A = [1,2,3,4,5,6,7,8,9,10];
//   0 1 2 3 4 5 6 7 8 9
let bit = new BIT(A);
console.log(bit.sum(0, 4))  // A[0..4] = 15 = 1 + 2 + 3 + 4 + 5
console.log(bit.sum(0, 9))  // A[0..9] = 55 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
```

*Python3*
```python
from typing import List
class BIT:
    def __init__(self, A: List[int]):
        self.N = len(A)
        self.A, self.S = A[:], [0] * (self.N + 1)
        for i in range(self.N):
            k = i + 1
            while k <= self.N:
                self.S[k] += self.A[i]
                k = self.next(k)

    def update(self, i: int, x: int) -> None:
        diff, self.A[i] = x - self.A[i], x
        k = i + 1
        while k <= self.N:
            self.S[k] += diff
            k = self.next(k)

    query = lambda self, i: self.S[i] + self.query(self.prev(i)) if i else 0
    sum = lambda self, i, j: self.query(j + 1) - self.query(i)
    prev = lambda self, i: i - (i & -i)
    next = lambda self, i: i + (i & -i)

A = [1,2,3,4,5,6,7,8,9,10]
#    0 1 2 3 4 5 6 7 8 9
bit = BIT(A)
print(bit.sum(0, 4))  # A[0..4] = 15 = 1 + 2 + 3 + 4 + 5
print(bit.sum(0, 9))  # A[0..9] = 55 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
```

*C++*
```cpp
#include <vector>

using namespace std;

using VI = vector<int>;
class NumArray {
    VI A, S; size_t N;
    int prev(int i) { return i - (i & -i); }
    int next(int i) { return i + (i & -i); }
    int query(int i) { return i ? S[i] + query(prev(i)) : 0; }
public:
    NumArray(VI& A) : A{ A }, S{ VI(A.size() + 1) }, N{ A.size() } {
        for (auto i{ 0 }; i < N; ++i)
            for (auto k{ i + 1 }; k <= N; k = next(k))
                S[k] += A[i];
    }
    void update(int i, int x) {
        auto diff = x - A[i]; A[i] = x;
        for (auto k{ i + 1 }; k <= N; k = next(k))
            S[k] += diff;
    }
    int sumRange(int i, int j) { return query(j + 1) - query(i); }
};
```