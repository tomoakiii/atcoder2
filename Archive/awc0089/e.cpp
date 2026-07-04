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
typedef pair<int,int> pii;


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

/* ---------------------------------------
 [How to]
 Overwrite by value x in range l to r
 LS.apply(l,r+1,x);

 Get sum in range l to r
 S gt = LS.prod(l, r+1)

 Get value at index i
 LS.get(i).value.val()
--------------------------------------- */
struct S{
    ll value=0;
    int size=1;
};
// 区間max。幅も和
S op(S a, S b){
  if(a.value<b.value) return a;
  else if(a.value>b.value) return b;
  else {
    a.size+=b.size;
    return a;
  }
}

// 単位減。幅はゼロ。op(a,e) → aとなるように
S e(){ return S(INF, 0); }

using F =  long long;
// 写像=代入。葉にxを代入するとモノイドには幅x要素を代入する
S mapping(F f, S x){
    x.value += f;
    return x;
}
// g(x)が先、f(g(x))を後に適用した場合の関数合成
F composition(F f, F g){ return f+g; }

// 恒等写像 = 無視されるべき写像
F id(){ return 0; }


int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> L(M),R(M);
    CC<ll> cc;
    cc.add(1);
    cc.add(N+1);
    rep(i,M) {
        cin>>L[i]>>R[i];
        cc.add(L[i]);
        cc.add(R[i]+1);
    }
    ll sz=cc.size();
    vector<S> v(sz);
    rep(i,sz-1){
      ll dl = cc[i+1]-cc[i];
      v[i].size=dl;
    }
    v[sz-1].size=0;
    lazy_segtree<S,op,e,F,mapping,composition,id> LZ(v);
    ll ans=0;
    ll K2=M-K;
    rep(i,K2){
        ll l=cc(L[i]);
        ll r=cc(R[i]+1);
        LZ.apply(l,r,1);
    }
    S fil = LZ.all_prod();
    if(fil.value==0) chmax(ans, N-fil.size);
    else chmax(ans,N);
    for(int i=K2-1; i>=0; i--){
      ll l=cc(L[i+K]);
      ll r=cc(R[i+K]+1);
      LZ.apply(l,r,1);
      l=cc(L[i]);
      r=cc(R[i]+1);
      LZ.apply(l,r,-1);
      S fil = LZ.all_prod();
      if(fil.value==0) chmax(ans, N-fil.size);
      else chmax(ans,N);
    }
    cout<<ans<<endl;
    return 0;
}