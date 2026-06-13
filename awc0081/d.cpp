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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    CC<ll> cc;
    vector<ll> A(N), C(N);
    ll ans = 0;
    rep(i,N) {
        cin>>A[i];
        cc.add(A[i]);
    }
    cc.add(0);
    rep(i,N) {
      cin>>C[i];
      ans += C[i];
    }
    ll M = cc.size();
    vector<ll> cost(M,-INF);
    cost[0]=0;
    rep(i,N) {
        auto cost2 = cost;
        ll a = cc(A[i]);
        rep(j,M) {
          if(j>=a) break;
          chmax(cost2[a], cost[j]+C[i]);
        }
        swap(cost2,cost);
    }
    ll mx = 0;
    rep(i,M) chmax(mx, cost[i]);
    cout<<ans-mx<<endl;
    return 0;
}