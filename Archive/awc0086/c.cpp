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
    ll N,M,Q;
    cin >> N >> M >> Q;
    CC<ll> cc;
    vector<ll> B(M);
    rep(i,M) {
        cin>>B[i];
        cc.add(B[i]);
    }
    vector<ll> L(Q),R(Q);
    rep(i,Q){
        ll l,r; cin>>l>>r;
        cc.add(l);
        cc.add(r);
        L[i]=l;
        R[i]=r;
    }
    ll K=cc.size();
    vector<ll> A(K+1);
    rep(i,Q){
        A[cc(L[i])]++;
        A[cc(R[i])+1]--;
    }
    rep(i,K) A[i+1]+=A[i];
    ll ans=0;
    for(auto b:B){
        if(A[cc(b)] % 2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}