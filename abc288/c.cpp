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
    dsu ds(N);
    vector<ll> nm(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ds.merge(a, b);
        nm[a]++;
    }
    ll ans = 0;
    vector<ll> nm2(N);
    rep(i, N) {
        nm2[ds.leader(i)] += nm[i];
    }
    for(auto v: ds.groups()) {
        if(v.size()-1 < nm2[ds.leader(v[0])]) {
            ans += nm2[ds.leader(v[0])] - v.size() + 1;
        }
    }
    cout << ans << endl;
    return 0;
}