#include <bits/stdc++.h>
using namespace std;


int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> X(N), Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    // (A1, ..., AN) と (A1 - x, ..., AN - x) をマージしながらソート (O(N))
    // そしてメディアンを答える
    auto calc = [&](const vector<long long> &A, long long x) {
        int N = (int)A.size();
        vector<long long> B(N);
        for (int i = 0; i < N; ++i) B[i] = A[i] - x;
        
        // ソートされた 2N 個の配列を作る
        vector<long long> v;
        int i = 0, j = 0;
        while (i < N || j < N) {
            if (i == N || A[i] >= B[j]) v.push_back(B[j++]);
            else v.push_back(A[i++]);
        }
        
        // メディアンに揃える
        long long median = v[N-1];
        long long res = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] < median) res += median - A[i];
            else if (A[i] > median + x) res += A[i] - (median + x);
        }
        return res;
    };

    // 二分探索
    long long low = -1, high = 1LL<<35;
    while (high - low > 1) {
        long long mid = (high + low) / 2;
        if (calc(X, mid) + calc(Y, mid) <= K) high = mid;
        else low = mid;
    }
    
    cout << high << endl;
}
