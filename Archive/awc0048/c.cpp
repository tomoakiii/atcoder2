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
    ll N,M;
    cin >> N>>M;
    vector<ll> H(N),S(N+1);
    rep(i,N) cin>>H[i];
    rep(i,M){
        int l,r;
        ll d;
        cin>>l>>r>>d;
        l--,r--;
        S[l]+=d;
        S[r+1]-=d;
    }
    rep(i,N)S[i+1]+=S[i];
    ll ans=0;
    rep(i,N){
        if(H[i]-S[i]>=1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}