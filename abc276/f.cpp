#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef modint998244353 mint;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(), A.end());
    mint invN2 = 1;
    invN2 = invN2 / N / N;
    mint SiAi = 0, SAi = 0;
    rep(i,N) {
        SiAi = SiAi + 2 * A[i] * (i+1);
        SAi = SAi + A[i];
        mint ans = invN2 * (SiAi - SAi);
        cout << ans.val() << endl;
    }
        
    return 0;
}