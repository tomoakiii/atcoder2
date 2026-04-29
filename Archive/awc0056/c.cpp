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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll sm=0, r=0;
    ll ans=0;
    rep(l,N) {
        while(r<N && sm<=K) {
            sm+=A[r++];
        }
        if(sm>K) chmax(ans,r-l-1);
        else chmax(ans,r-l);
        sm-=A[l];
    }
    cout<<ans<<endl;
    return 0;
}