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
    cin >> N>>Q;

    vector<ll> Y(N),P(N);
    CC<ll> cc;
    rep(i,N) {
        ll y,p;
        cin>>y>>p;
        Y[i]=y, P[i]=p;
        cc.add(y);
    }
    vector<ll> L(Q);
    rep(i,Q) {
        ll l; cin>>l;
        cc.add(l);
        L[i]=l;
    }
    int M=cc.size();
    fenwick_tree<ll> FT(M+1);
    rep(i,N) {
        int y=cc(Y[i]);
        FT.add(y,P[i]);
    }
    rep(i,Q){
        cout << FT.sum(cc(L[i]),M) << endl;
    }
    return 0;
}