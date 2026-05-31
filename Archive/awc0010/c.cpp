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

int main(){
    ll N,K,Q;
    cin >> N >> K >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    dsu UF(N);
    rep(i,N-1) {
        if( abs(A[i]-A[i+1]) <= K ) UF.merge(i,i+1);
    }
    while(Q--) {
        ll l,r; cin>>l>>r; l--,r--;
        if(UF.same(l,r)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}