#include <bits/stdc++.h>
using namespace std;

class combination{
public:
    long long N, R;
    vector<vector<long long>> comb = {};
    combination(long long n, long long r) : N(n), R(r){
        vector<bool> b(n, false);
        fill(b.end() - r, b.end(), true);
        do {
            vector<long long> c = {};
            for (long long i=0; i<n; i++) if (b[i]) c.push_back(i+1);
            comb.push_back(c);
        } while (std::next_permutation(b.begin(), b.end()));

    }
};

// N=5000以下で使うこと
void Combination(int MAX_N, ll MOD) {
    vector comb(MAX_N+1, vector<ll>(MAX_N));
    for (int i = 0; i <= MAX_N; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + Comb[i - 1][j]) % MOD;
        }
    }
}


// C0個・C1個・・・CN個のボールを並べる組み合わせの数
// (C0+C1+...+CN)! / (C0! * C1! * ... * C2!) を変換すると
// Comb(total, C0) * Comb(total-C0, C1) * ... になる。
// total <= 5000 で使うこと
void duplicate_combination(ll MOD){
    ll N; cin>>N;
    vector<ll> C(N);
    int total = 0;
    rep(i,N) {
        cin>>C[i];
        total += C[i];
    }
    ll ans = 1;        
    rep(i, N){
        ans *= Comb[total][C[i]];
        ans %= MOD;
        total -= C[i];
    }
    cout << ans << endl;
}



int main(){
    combination c = combination(36, 3);
    cout << "Yes" << endl;

    return 0;
}