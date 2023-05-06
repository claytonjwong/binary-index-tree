class NumArray(A: IntArray) {
    var A: IntArray
    var S: IntArray
    var N: Int
    var prev = { i: Int -> i - (i and i.inv() + 1) }
    var next = { i: Int -> i + (i and i.inv() + 1) }
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
    fun query(i_: Int): Int {
        var t = 0
        var i = i_
        while (0 < i) {
            t += S[i]; i = prev(i)
        }
        return t
    }
    var sumRange = { i: Int, j: Int -> query(j + 1) - query(i) }
}
