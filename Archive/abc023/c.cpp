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
    ll R,C,K;
    cin >> R >> C >> K;
    ll N;
    cin>>N;
    unordered_map<ll,ll> mpr, mpc;
    vector<ll> Rv(N), Cv(N);
    vector<ll> cnt(N+1);
    rep(i,N) {
        int r, c; cin>>r>>c; r--,c--;
        mpr[r]++;
        mpc[c]++;
        Rv[i] = r;
        Cv[i] = c;
    }
    rep(c,C) cnt[mpc[c]]++;
    ll ans = 0;
    rep(i,N) {
        if(mpr[Rv[i]] + mpc[Cv[i]] - 1 == K) ans++;
        if(mpr[Rv[i]] + mpc[Cv[i]] == K) ans--;
    }
    rep(r,R) {
        if(K >= mpr[r]) ans += cnt[K - mpr[r]];
    }

    cout << ans << endl;
    return 0;
}