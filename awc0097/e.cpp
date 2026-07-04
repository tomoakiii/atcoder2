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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> H(N);
    rep(i,N) cin>>H[i];
    vector<ll> P(N);
    rep(i,N-1) P[i+1]=P[i]+K;
    rep(i,N) {
        H[i]+=P[i];
        H[i]-=H[0];
    }

    ll sm=0;
    ll ans=0;
    rep(i,N-1){
        if(H[i]>0) sm+=H[i];
        else {
            ll rm = abs(H[i]);
            if(rm > sm){
                ans += rm;
            } else {
                ans += sm;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}