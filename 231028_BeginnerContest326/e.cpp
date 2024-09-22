#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<mint> dp(N);
    mint invN = 1;
    invN = invN/N;    
    vector<mint> B;    

    dp[N-1] = A[N-1] * invN;
    mint dpSum = dp[N-1];
    mint cnt = 1;
    for (int i=N-2; i>=0; i--) {
        dp[i] = A[i] * invN + dpSum * cnt * invN;
        dpSum += dp[i];
        cnt++;
    }
    cout << dpSum.val() << endl;
    return 0;
    
}