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


struct S { ll val, num;};
S op(S a, S b) {
  if (a.val < b.val) return a;
  if (a.val > b.val) return b;
  a.num += b.num;
  return a;
}
S e() { return S(INF,0);}
typedef ll F;
S mapping(F f, S x) { x.val += f; return x;}
F composition(F f, F g) { return f+g;}
F id() { return 0;}


int main(){
    ll H,W,h,w,N;
    cin >> H>>W>>h>>w>>N;
    H-=h-1, W-=w-1;
    map<ll,vector<tuple<ll,ll,int>>> mp;
    CC cc;
    rep(i,N) {
        ll r,c; cin>>r>>c;
        ll r0 = max(0ll, r-h);
        ll c0 = max(0ll, c-w);
        r = min(r, H);
        c = min(c, W);
        mp[c0].push_back({r0, r, 1});
        mp[c].push_back({r0, r, -1});
        cc.add(r0); cc.add(r);
    }
    mp[W].push_back({0,0,0});
    cc.add(0); cc.add(H);
    ll M = cc.size();
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(M);
    rep(i,M-1) {
        seg.set(i,S(0, cc[i+1]-cc[i]) );
    }
    ll ans = 0;
    ll pc = 0;
    for(auto [c, tp]: mp) {
        S s = seg.all_prod();
        if(s.val==0) ans+=s.num*(c-pc);
        for(auto [r0,r,x]:tp) {
            seg.apply(cc(r0),cc(r),x);
        }
        pc = c;
    }
    cout<<ans<<endl;
    return 0;
}