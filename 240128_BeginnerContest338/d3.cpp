#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M);
    for (ll i = 0; i < M; i++) {
        cin >> X[i];
        X[i]--;
    }
    vector<ll> diffs(M - 1);
    for (ll i = 0; i < M - 1; i++) {
        diffs[i] = abs(X[i] - X[i + 1]);
    }
    // 最初は橋 N を封鎖した場合のコストを愚直に求める
    ll ans = 0;
    for (ll i = 0; i < M - 1; i++) {
        ans += diffs[i];
    }
    vector<vector<ll>> idxs(N, vector<ll>(0));
    for (ll i = 0; i < M; i++) {
        idxs[X[i]].push_back(i);
    }
    ll INF = 100000000000007;
    // すべての橋に対して，封鎖した際のコストを差分計算によって求めていく
    ll now_ans = ans;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < idxs[i].size(); j++) {
            ll val = idxs[i][j];
            if (val > 0) {
                ll prev = diffs[val - 1];
                now_ans = (now_ans - prev + (N - prev));
                diffs[val - 1] = N - prev;
            }
            if (val < M - 1) {
                ll prev = diffs[val];
                now_ans = (now_ans - prev + (N - prev));
                diffs[val] = N - prev;
            }
        }
        ans = min(ans, now_ans);
    }
    cout << ans << endl;
}
