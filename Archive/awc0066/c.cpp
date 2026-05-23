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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> W(N), D(N+1);
    rep(i,N) cin>>W[i];

    rep(i,Q) {
        ll l,r,d; cin>>l>>r>>d;
        l--,r--;
        D[l]+=d;
        D[r+1]-=d;
    }
    rep(i,N) D[i+1]+=D[i];
    ll ans=0;
    rep(i,N) {
        if(W[i]<=D[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}