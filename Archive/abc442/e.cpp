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

struct V {
  ll x, y; int i;
  V(ll x=0, ll y=0, int i=-1): x(x), y(y), i(i) {}
  ll cross(const V& a) const { return x*a.y - y*a.x;}
  bool up() const { return y > 0 || (y == 0 && x > 0);}
  bool operator<(const V& a) const {
    if (up() != a.up()) return up();
    return cross(a) > 0;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<V> ps(n);
  rep(i,n) cin >> ps[i].x >> ps[i].y, ps[i].i = i;

  sort(ps.begin(), ps.end());
  vector<int> idx(n);
  rep(i,n) idx[ps[i].i] = i;

  vector<int> l(n), r(n,n-1);
  rep(i,n-1) if (ps[i] < ps[i+1]) l[i+1] = i+1; else  l[i+1] = l[i];
  for (int i = n-2; i >= 0; i--) {
    if (ps[i] < ps[i+1]) r[i] = i; else r[i] = r[i+1];
  }

  rep(qi,q) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    swap(a,b);
    a = l[idx[a]];
    b = r[idx[b]];
    if (a > b) b += n;
    cout << (b-a+1) << endl;
  }
  return 0;
}