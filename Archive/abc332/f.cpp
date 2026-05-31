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
typedef modint998244353 mint;

vector<vector<mint>> mult(vector<vector<mint>> A, vector<vector<mint>> B){
    vector C(2, vector<mint>(2));
    rep(i,A.size()) {
        rep(k, B[0].size()) {
            rep(j, A[0].size()) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
    return C;
}

vector<vector<mint>> unit(int n){
    vector E(n,vector<mint>(n, 0));
    rep(i,n) E[i][i]= 1;
    return E;
}

using S = mint;
struct F{
  mint a,b;
  F(mint a=1, mint b=0): a(a),b(b){}
};
S op(S a, S b){ return a+b; }
S e(){ return 0; }
S mapping(F f, S x){
    return f.a*x + f.b;
}
F composition(F f, F g){
  return F(f.a * g.a, g.b+g.a*f.a);
}
F id(){ return F(1,0); }


int main(){
    ll N,M; cin>>N>>M;
    modint p=0;
    vector<mint> A(N);
    rep(i,N) {
        ll a; cin>>a;
        A[i] = a;
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);
    rep(i,M) {
        int l,r; ll x;
        cin>>l>>r>>x;
        l--,r--;
        mint X = x;
        mint L = (r-l+1);
        mint invL = 1;
        invL /= L;
        F f;
        f.b = X*invL;
        f.a = (L-1) * invL;
        LS.apply(l,r+1,f);
    }

    mint ans= 0;
    rep(i,N) ans+=LS.get(i);
    ans/=N;
    cout<<ans.val()<<endl;
    return 0;
}