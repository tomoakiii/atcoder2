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
    ll N,D;
    cin >> N >> D;
    vector<pair<ll,ll>> XS(N);
    rep(i,N) cin>>XS[i].first>>XS[i].second;
    sort(XS.begin(),XS.end());
    vector<ll> S(N+1),X(N);
    rep(i,N) X[i]=XS[i].first;
    rep(i,N) S[i+1]=S[i]+XS[i].second;
    ll ans=0;
    rep(i,N) {
        auto r=upper_bound(X.begin(),X.end(),X[i]+D)-X.begin();
        ll sm=S[r]-S[i+1];
        ans+=XS[i].second*sm;
    }
    cout<<ans<<endl;
    return 0;
}