#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> P(N),L(M),T(K);
    rep(i,N) cin>>P[i];
    rep(i,M) cin>>L[i];
    ll ml=0;
    rep(i,K) {
        int t; cin>>t;
        t--;
        chmax(ml,L[t]);
    }
    ll ans=0;
    rep(i,N){
        if(P[i]<=ml)ans+=P[i];
    }
    cout<<ans<<endl;
    return 0;
}