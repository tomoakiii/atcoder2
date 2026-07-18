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
    ll N,M,K;
    cin >> N >> M >> K;
    ll ans = 0;
    rep(i,N) {
        ll sm = 0;
        ll mn = INF, mx = 0;
        rep(j,M) {
            ll s; cin>>s;
            sm += s;
            chmin(mn, s);
            chmax(mx, s);
        }
        if(M<=2) {
            if(sm / M < K) ans++;
        } else {
            sm -= (mn+mx);
            if(sm / (M-2) < K) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}