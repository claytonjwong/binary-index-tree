type VI = Vec<i32>;
struct BIT { A: VI, S: VI }
impl BIT {
    fn new(A: VI) -> BIT {
        let N = A.len();
        let mut S = vec![0; N + 1];
        for i in 0..N {
            let mut k = i + 1;
            while k <= N {
                S[k] += A[i]; k = BIT::next(k);
            }
        }
        BIT { A, S }
    }
    fn update(&mut self, i: usize, x: i32) {
        let diff = x - self.A[i]; self.A[i] = x;
        let mut k = i + 1;
        while k <= self.A.len() {
            self.S[k] += diff; k = BIT::next(k);
        }
    }
    fn query(&self, i: usize) -> i32 {
        if 0 < i { self.S[i] + self.query(BIT::prev(i)) } else { 0 }
    }
    fn sum(&self, i: usize, j: usize) -> i32 { self.query(j + 1) - self.query(i) }
    fn prev(i: usize) -> usize { (i as i32 - (i as i32 & -1 * i as i32)) as usize }
    fn next(i: usize) -> usize { (i as i32 + (i as i32 & -1 * i as i32)) as usize }
}

fn main() {
    let A = vec![1,2,3,4,5,6,7,8,9,10];
    //           0 1 2 3 4 5 6 7 8 9
    let bit = BIT::new(A);
    println!("{}", bit.sum(0, 4));  // A[0..4] = 15 = 1 + 2 + 3 + 4 + 5
    println!("{}", bit.sum(0, 9));  // A[0..9] = 55 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
}
