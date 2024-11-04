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
    ll N, M;
    cin >> N >> M;
    vector A(N, vector<ll>(M));
    map<ll, pair<int, int>> mp;
    rep(i,N) rep(j,M) {
        ll a;
        cin >> a;
        mp[a] = {i, j};
    }
    fenwick_tree<ll> fw(N+1);
    ll ans = 0;
    for(auto m : mp) {
        auto [i, j] = m.second;
        ans += (j+1) * (N-1-i);
        ans += fw.sum(i+1, N);
        fw.add(i, 1);
    }
    
    cout << ans << endl;
    return 0;
}