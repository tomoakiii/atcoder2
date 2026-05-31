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

using S = int;
using F = int;
S op(S l, S r) {return max(l, r);}
S e() {return 0;}
S mapping (F l, S r) {return r+=l;}
F composition (F l, F r) {return l+r;}
F id() {return 0;}


int main(){
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pair<ll,ll>> XH(N);
    rep(i,N) cin>>XH[i].first>>XH[i].second;
    sort(XH.begin(), XH.end());
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<int>(N, 0));
    ll ans = 0;
    rep(i,N) {
        ll dmg = LS.get(i);
        if(XH[i].second > dmg){
            pair<ll,ll> key = {XH[i].first+2*D, (ll)INF};
            int nx = upper_bound(XH.begin(), XH.end(), key) - XH.begin();
            ll tm = (XH[i].second-dmg+A-1)/A;
            ans += tm;
            LS.apply(i, nx, tm*A);
        }
    }
    cout << ans << endl;
    return 0;
}