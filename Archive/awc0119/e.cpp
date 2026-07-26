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
struct S{
    ll value=0;
    int size=1;
};
// 区間和。幅も和
S op(S a, S b){ return S(a.value+b.value, a.size+b.size); }
// 単位減。幅はゼロ。op(a,e) → aとなるように
S e(){ return S(0, 0); }
using F =  long long;
// 写像=代入。葉にxを代入するとモノイドには幅x要素を代入する
S mapping(F f, S x){
    x.value += f * x.size;
    return x;
}
// g(x)が先、f(g(x))を後に適用した場合の関数合成
// 基本は後勝ちでf。ただしfが処理なしならgをそのまま。
F composition(F f, F g){ return f + g; }
// 恒等写像 = 無視されるべき写像
F id(){ return 0; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<S> A(N);
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);
    while(Q--){
        ll t; cin >> t;
        if(t==1){
            ll l,r; cin >> l >> r; l--,r--;
            LS.apply(l,r+1,1);
        } else if(t==2){
            ll i; cin >> i; i--;
            LS.set(i, S(0,1));
        } else {
            ll l,r; cin >> l >> r; l--,r--;
            cout << LS.prod(l,r+1).value << endl;
        }
    }
    return 0;
}