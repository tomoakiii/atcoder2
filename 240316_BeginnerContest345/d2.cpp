#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
const ll INF = 1e18;

struct D {
  ll val; int col;
  D(ll val=-INF, int col=-1): val(val), col(col) {}
};
struct Top2 {
  D a, b;
  Top2(D a=D(), D b=D(-INF,-2)): a(a), b(b) {}
  void operator<=(D d) {
    if (b.val < d.val) {
      swap(b,d);
      if (a.val < b.val) swap(a,b);
    }
    if (a.col == b.col) b = d;
  }
  void operator<=(Top2 x) {
    *this <= x.a;
    *this <= x.b;
  }
  ll get(int c) {
    if (a.col == c) return b.val;
    return a.val;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n), v(n);
  rep(i,n) cin >> c[i] >> v[i];

  vector<Top2> dp(k+1);
  dp[0] = Top2(D(0,-1));

  rep(i,n) {
    vector<Top2> old(k+1);
    swap(old, dp);
    rep(j,k+1) {
      if (j < k) dp[j+1] <= old[j];
      dp[j] <= D(old[j].get(c[i]) + v[i], c[i]);
    }
  }

  ll ans = dp[k].a.val;
  if (ans < 0) ans = -1;
  cout << ans << endl;
  return 0;
}