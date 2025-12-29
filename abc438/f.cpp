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
    ll N;
    cin >> N;
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        if(v>u) swap(u,v);
        uv[u].emplace_back(v);
    }
    dsu UF(N);
    map<int,ll> cld;
    ll ans = 0;
    rep(i,N) {
        ll clsm = 0;
        for(auto nx: uv[i]) {
            int ld = UF.leader(nx);
            clsm += cld[ld];
        }
        ll cnt = clsm + 1;
        for(auto nx: uv[i]) {
            int ld = UF.leader(nx);
            cnt += cld[ld] * (clsm - cld[ld]);
            clsm -= cld[ld];
            UF.merge(i, nx);
        }
        int ld = UF.leader(i);
        cld[ld] = cnt;
        ans += cnt * (i+1);
    }
    /*
    bool flg = true;
    for(int i=1; i<N; i++) {
        if(uv[i].size() > 1) flg = false;
    }
    if(flg) ans += N;
    */
    cout<<ans<<endl;
    return 0;
}
