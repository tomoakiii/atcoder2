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
    ll N,M,C;
    cin >> N >> M >> C;
    vector<ll> B(M);
    rep(i,M) cin>>B[i];
    ll ans = 0;
    rep(i,N) {
        ll sm = 0;
        rep(j,M) {
            ll a; cin>>a;
            sm += a * B[j];
        }
        if(sm + C > 0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}