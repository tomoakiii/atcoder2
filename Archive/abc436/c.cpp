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
    cin >> N >> M;
    set<pair<ll,ll>> st;
    ll ans = 0;
    ll dy[] = {0, 1, 0, 1};
    ll dx[] = {0, 0, 1, 1};
    rep(i,M) {
        int r, c; cin>>r>>c;
        bool flg = true;
        rep(k,4) {
            ll ny = r + dy[k];
            ll nx = c + dx[k];
            if(st.contains({ny, nx})) {
                flg = false;
                break;
            }
        }
        if(flg) {
            ans++;
            rep(k,4) {
                ll ny = r + dy[k];
                ll nx = c + dx[k];
                st.insert({ny,nx});
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}