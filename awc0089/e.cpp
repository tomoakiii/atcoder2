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
S op(S a, S b){ return S(max(a.value,b.value), a.size+b.size); }
S op2(S a, S b){ return S(min(a.value,b.value), a.size+b.size); }

// 単位減。幅はゼロ。op(a,e) → aとなるように
S e(){ return S(-INF, 0); }
S e2(){ return S(INF, 0); }

using F =  long long;
// 写像=代入。葉にxを代入するとモノイドには幅x要素を代入する
S mapping(F f, S x){
    if(f!=-INF) x.value = f * x.size;
    return x;
}
S mapping2(F f, S x){
    if(f!=INF) x.value = f * x.size;
    return x;
}
// g(x)が先、f(g(x))を後に適用した場合の関数合成
// 基本は後勝ちでf。ただしfが処理なしならgをそのまま。
F composition(F f, F g){ return (f!=-INF? f : g); }
F composition2(F f, F g){ return (f!=INF? f : g); }

// 恒等写像 = 無視されるべき写像
F id(){ return -INF; }
F id2(){ return INF; }


int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> L(M),R(M);
    CC<ll> cc;
    rep(i,M) {
        cin>>L[i]>>R[i];
        cc.add(L[i]);
        cc.add(R[i]);
    }

    ll K=cc.size();
    lazy_segtree<S,op,e,F,mapping,composition,id> LZ(K);
    lazy_segtree<S,op2,e2,F,mapping2,composition2,id2> LZ2(K);
    rep(i,M){
        ll l=cc(L[i]);
        ll r=cc(R[i]);
        LZ.apply(l,r+1);
        LZ2.apply(l,r+1);
    }
    priority_queue<pii,vector<pii>,greater<pii>>que;
    rep(i,M){

    }
    return 0;
}