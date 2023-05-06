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
    prev = i => i - (i & ~i + 1);
    next = i => i + (i & ~i + 1);
}

A = [1,2,3,4,5,6,7,8,9,10];
//   0 1 2 3 4 5 6 7 8 9
let bit = new BIT(A);
console.log(bit.sum(0, 4))  // A[0..4] = 15 = 1 + 2 + 3 + 4 + 5
console.log(bit.sum(0, 9))  // A[0..9] = 55 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10