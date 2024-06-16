#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template<typename T=int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC(): initialized(false) {}
  void add(T x) { xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  CC<int> cc;
  rep(i,n) cc.add(a[i]);

  fenwick_tree<int> tcnt(n);
  fenwick_tree<ll> tsum(n);
  ll ans = 0;
  rep(i,n) {
    int ai = cc(a[i]);
    ans += (ll)a[i]*tcnt.sum(0,ai);
    ans -= tsum.sum(0,ai);
    tcnt.add(ai,1);
    tsum.add(ai,a[i]);
  }

  cout << ans << endl;
  return 0;
}