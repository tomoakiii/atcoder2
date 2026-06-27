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
    ll N,K; cin>>N>>K;
    vector<pair<ll,ll>> RL(N);
    rep(i,N) cin>>RL[i].second>>RL[i].first;
    sort(RL.begin(), RL.end());
    ll nx = -1;
    ll cnt = 0;
    rep(i,N) {
        auto [r, l] = RL[i];
        if(l <= nx) continue;
        nx = r;
        cnt++;
    }
    if(cnt < K) {
        cout << -1 << endl;
        return 0;
    }
    ll ng = 1e10, ok = 0;
    while(ng - ok > 1) {
        ll c = (ok + ng) / 2;
        ll nx = -1;
        ll cnt = 0;
        rep(i,N) {
            auto [r, l] = RL[i];
            if(l <= nx) continue;
            nx = r + c;
            cnt++;
        }
        if(cnt >= K) ok = c;
        else ng = c;
    }
    cout << ok+1 << endl;
    return 0;
}