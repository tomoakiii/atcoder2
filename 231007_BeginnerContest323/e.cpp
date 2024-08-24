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
    ll N, X;
    cin >> N >> X;
    vector<ll> T(N, 0);
    rep(i, N) cin >> T[i];
    vector<mint> dp(X+1);
    struct edge{
        mint val;
        int time;
    };
    set<ll> que;
    que.insert(0);
    dp[0] = 1;
    mint invN = 1;
    invN /= N;
    auto it = que.begin();
    while(it != que.end()){
        ll q = *it;        
        rep(i, N) {
            if (q + T[i] > X) continue;
            dp[q + T[i]] += dp[q] * invN;
            que.insert(q+T[i]);            
        }
        it++;
    }
    mint ans = 0;
    for(ll t=max((ll)0, X-T[0]+1); t<=X; t++) {
        ans += dp[t] * invN;
    }
    cout << ans.val() << endl;
    return 0;
}