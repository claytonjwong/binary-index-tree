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
    int sum(int i, int j) { return query(j + 1) - query(i); }
};
