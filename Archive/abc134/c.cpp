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
using S = int;
using F = int;
S op(S l, S r) {return max(l, r);}
S e() {return 0;}

int main(){
    ll N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    segtree<S,op,e> ST(A);
    rep(i,N) {
        ST.set(i,0);
        cout<<ST.all_prod()<<endl;
        ST.set(i,A[i]);
    }

    return 0;
}