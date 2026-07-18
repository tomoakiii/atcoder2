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
    ll N,M;
    cin >> N >> M;
    vector<ll> H(N),T(N),A(N+1);
    rep(i,N) cin>>H[i];
    rep(i,N) cin>>T[i];
    rep(i,M){
        ll l,r,w; cin>>l>>r>>w;
        l--,r--;
        A[l]+=w; A[r+1]-=w;
    }
    ll ans=0;
    rep(i,N){
        A[i+1]+=A[i];
        if(A[i]+H[i]>=T[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}