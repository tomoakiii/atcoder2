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
typedef tuple<ll,int,int>  tlii;
int main(){
    ll N, M;
    cin >> N >> M;
    vector<tlii> t(M);
    rep(i,M) {
        int u,v;ll c;
        cin>>u>>v>>c;
        u--, v--;
        t[i] = make_tuple(c, u, v);
    }
    sort(t.begin(), t.end());
    dsu UF(N);
    ll ans = 0;
    for(auto [c, i, j]: t) {
        if(UF.same(i,j)) continue;
        UF.merge(i,j);
        ans += c;
    }
    cout << ans << endl;
    return 0;
}