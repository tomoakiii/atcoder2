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
    ll N,Q;
    cin >> N >> Q;
    dsu UF(N*2);
    ll ans=0;
    bool ok = true;
    vector<ll> cnt(2*N,0);    
    rep(i,N) cnt[i+N]++;

    while(Q--) {
        int u,v; cin>>u>>v; u--,v--;        
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        if(UF.same(u, v+N) || UF.same(v, u+N)) {
            cout << ans << endl;
            continue;
        }
        auto k1a = cnt[UF.leader(u)];
        auto k1b = cnt[UF.leader(u+N)];
        auto k2a = cnt[UF.leader(v)];
        auto k2b = cnt[UF.leader(v+N)];
        ans-=min(k1a,k1b);
        ans-=min(k2a,k2b);
        int nla = UF.merge(u,v+N);
        int nlb = UF.merge(u+N,v);
        if(UF.same(nla, nlb)) {
            ok = false;
        }
        cnt[nla] = k1a+k2b;
        cnt[nlb] = k2a+k1b;
        ans += min(cnt[nla], cnt[nlb]);
        if(ok) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}