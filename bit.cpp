#include <vector>

using namespace std;

using LL = long long;
using VI = vector<int>;
using VL = vector<LL>;
class BIT {
    VI A;
    VL S;
    int N;
    int prev(int i) { return i - (i & -i); }
    int next(int i) { return i + (i & -i); }
public:
    BIT(const VI& A) : A{ A }, S{ VL(A.size() + 1) }, N{ int(A.size()) } {
        for (auto i{ 0 }; i < N; ++i)
            for (auto k{ i + 1 }; k <= N; k = next(k))
                S[k] += A[i];
    }
    void update(int i, int x) {
        auto diff = x - A[i]; A[i] = x;
        for (auto k{ i + 1 }; k <= N; k = next(k))
            S[k] += diff;
    }
    LL query(int i, int t = 0) {
        while (i)
            t += S[i], i = prev(i);
        return t;
    }
    LL sum(int i, int j) {
        return query(j + 1) - query(i);
    }
};
