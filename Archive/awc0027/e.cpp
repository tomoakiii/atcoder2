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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    CC<ll> cc;
    vector<ll> B(N+1);
    cc.add(0);
    cc.add(K);
    rep(i,N) {
        B[i+1] += B[i] + A[i] + M;
        cc.add(B[i+1]);
        cc.add(B[i+1]+K);
    }
    ll ans = 0;
    fenwick_tree<ll> FT(cc.size()+1);
    rep(i,N+1) {
        FT.add(cc(B[i]), 1);
    }
    rep(i,N) {
        FT.add(cc(B[i]), -1);
        ans+=FT.sum(0, cc(B[i]+K)+1);
    }
    cout<<ans<<endl;
    return 0;
}