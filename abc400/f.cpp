#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1000000000000000010;
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }

int main() {
	int n;
	cin >> n;
	vector<int> c(2 * n);
	rep(i, n) {
		cin >> c[i];
		c[i]--;
		c[n + i] = c[i];
	}
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	vector dp(2 * n + 1, vector(2 * n + 1, INF)); // 全部 0 にする コスト
	rep(i, 2 * n + 1) { dp[i][i] = 0; }
	for (int l = 2 * n; l >= 0; l--) {
        vector<ll> ep(2*n+1, INF);
        ep[l] = 0;
		for (int r = l + 1; r <= 2 * n; r++) {
			for (int m = l + 1; m < r; m++) {
				chmin(dp[l][r], dp[l][m] + dp[m][r]);
				chmin(ep[r], ep[m] + dp[m][r]);
			}
			if (c[l] == c[r - 1]) {
				chmin(ep[r], ep[r - 1]);
				chmin(dp[l][r], ep[r] + r - l + x[c[l]]);
			}
		}
	}
	ll ans = INF;
	rep(i, n) chmin(ans, dp[i][n + i]);
	cout << ans << '\n';
}
