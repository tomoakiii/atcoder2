#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
template <typename T>
inline bool chmax(T& a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T& a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

typedef modint998244353 mint;

/* ---------------------------------------
 [How to]
 Get max value in range l to r
 LS.prod(l,r+1);

 Add x in range l to r
 LS.apply(l,r+1,x);
--------------------------------------- */
using S = ll;
using F = ll;
S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F l, S r) { return r += l; }
F composition(F l, F r) { return l + r; }
F id() { return 0; }



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
    mint value;
    int size;
};
// 区間和。幅も和
S op(S a, S b){ return S(a.value+b.value, a.size+b.size); }
// 単位減。幅はゼロ。op(a,e) → aとなるように
S e(){ return S(0, 0); }
using F =  long long;
// 写像=代入。葉にxを代入するとモノイドには幅x要素を代入する
S mapping(F f, S x){
    if(f!=INF) x.value = f * x.size;
    return x;
}
// g(x)が先、f(g(x))を後に適用した場合の関数合成
// 基本は後勝ちでf。ただしfが処理なしならgをそのまま。
F composition(F f, F g){ return (f!=INF? f : g); }
// 恒等写像 = 無視されるべき写像
F id(){ return INF; }




/* ---------------------------------------
 [How to]
 Get minimum value and its index in range l to r
 S gt = LS.prod(l, r+1)
 gt.first -> value
 gt.second -> index

 Add value x at range l to r
 LS.apply(l, r+1, x) ;
--------------------------------------- */
using S = pair<ll,int>;
using F = ll;

S op(S a, S b){ return std::min(a, b); }
S e(){ return {INF, -1}; }
S mapping(F f, S x){
    x.first += f;
    return x;
}
F composition(F f, F g){ return f+g; }
F id(){ return 0; }




/* ---------------------------------------
 [How to]
 Update value in range l to r
 A[i] = a * A[i] + b

 Add value x at range l to r
 LS.apply(l, r+1, x) ;
--------------------------------------- */
using S = mint;
struct F{
  mint a,b;
  F(mint a=1, mint b=0): a(a),b(b){}
};
S op(S a, S b){ return a+b; }
S e(){ return 0; }
S mapping(F f, S x){
    return a*x + b;
}
F composition(F f, F g){
  return F(f.a * g.a, g.b+g.a*f.a);
}
F id(){ return F(1,0); }


int main(){
  ll N; cin>>N;
  lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<int>(N, 0));
  return 0;
}



/* ---------------------------------------
 [How to]
 区間内の最小値を求め、その最小値がいくつあるかを数える。
 更新→区間内に1を足して、各々の個数が更新される。
 ABC449-F問題
 https://atcoder.jp/contests/abc449/submissions/me
--------------------------------------- */
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
