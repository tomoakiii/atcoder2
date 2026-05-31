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
    ll N,K,D;
    cin >> N >> K >> D;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    ll ful=1ll<<N;
    ll ans=0;
    rep(S,ful) {
        ll sm=0;
        ll del=0;
        rep(i,N){
            if(S>>i & 1) {
                sm+=B[i];
                del+=A[i];
            }
        }
        if(sm>=K){
            del -= D*(sm-K);
        }
        chmax(ans,del);
    }
    cout<<ans<<endl;
    return 0;
}