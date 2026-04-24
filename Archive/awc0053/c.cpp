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
    vector<ll> L(N),R(N),C(N);
    CC<ll> cc;
    rep(i,N) {
        ll x,l,r; cin>>x>>l>>r>>C[i];
        L[i]=x-l;
        cc.add(L[i]);
        R[i]=x+r;
        cc.add(R[i]);
        cc.add(R[i]+1);
    }
    ll M=cc.size();
    vector<ll> FT(M+1);
    rep(i,N){
        FT[cc(L[i])]+=C[i];
        FT[cc(R[i]+1)]-=C[i];
    }
    ll ans=0;
    rep(i,M){
        FT[i+1]+=FT[i];
        chmax(ans,FT[i]);
    }
    cout<<ans<<endl;
    return 0;
}