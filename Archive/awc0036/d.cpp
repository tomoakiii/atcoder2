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
    ll N;
    cin >> N;
    vector<ll> S(N),E(N);
    CC cc;
    rep(i,N) {
        cin>>S[i]>>E[i];
        cc.add(S[i]);
        cc.add(E[i]);
    }
    ll M=cc.size();
    vector<ll> A(M+1);
    rep(i,N) {
        A[cc(S[i])]++;
        A[cc(E[i])]--;
    }
    ll ans=0;
    rep(i,M) {
        A[i+1]+=A[i];
        chmax(ans,A[i]);
    }
    cout<<ans<<endl;
    return 0;
}