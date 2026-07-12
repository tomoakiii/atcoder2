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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll sm = 0;
    rep(i,N) sm+=A[i];
    ll ans = 0;
    ll mx = -INF;
    rep(i,N) {
        if(chmax(mx,abs(N*A[i]-sm))) ans=i+1;
    }
    cout<<ans<<endl;
    return 0;
}