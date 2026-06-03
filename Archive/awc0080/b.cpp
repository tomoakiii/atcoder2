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
int main(){
    ll N,Q;
    cin >> N >> Q;
    CC<ll>cc;
    vector<ll> A(N), B(Q);
    rep(i,N) {
        cin>>A[i];
        cc.add(A[i]);
    }
    rep(i,Q) {
        cin >> B[i];
        cc.add(B[i]);
    }
    ll M = cc.size();
    fenwick_tree<ll> FT(M);
    rep(i,N) {
        FT.add(cc(A[i]),1);
    }
    ll ans = 0;
    for(auto x: B) {
        ll sm = FT.sum(0,cc(x));
        ll p = sm - ans;
        chmax(p, 0LL);
        cout << p << endl;
        chmax(ans, sm);
    }
    return 0;
}