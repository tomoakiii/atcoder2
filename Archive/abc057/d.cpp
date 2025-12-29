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
    ll N,A,B;
    cin >> N >> A >> B;
    map<ll,ll> mp;
    rep(i,N) {
        ll v; cin>>v;
        mp[-v]++;
    }

    ll MAX_N = 100;
    vector comb(MAX_N+1, vector<ll>(MAX_N));
    for (int i = 0; i <= MAX_N; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
        }
    }

    map<pair<ll,ll>, ll> ans;
    for(ll x = A; x <= B; x++) {
        ll tmp = 0;
        ll vtot = 0;
        for(auto [v, c]: mp) {
            if(tmp + c >= x) {
                ll rm = x - tmp;
                vtot += (-v) * rm;
                ll g = gcd(vtot, x);
                ans[{vtot/g, x/g}] += comb[c][rm];
                break;
            } else {
                tmp += c;
                vtot += (-v) * c;
            }
        }
    }
    double mx = 0;
    ll ansv = 0;
    for(auto [vv, c]: ans) {
        auto [y,x] = vv;
        double v = double(y)/double(x);
        if(chmax(mx, v)) {
            ansv = c;
        }
    }
    printf("%.10f\n%lld\n", mx, ansv);
    return 0;
}