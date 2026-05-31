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
    vector<tuple<ll,int,int>> vec(M);

    rep(i,M) {
        int u,v;
        ll c; cin>>u>>v>>c;
        u--, v--;
        vec[i] = make_tuple(c,u,v);
    }
    sort(vec.begin(),vec.end());
    dsu UF(N);
    ll ans=0;
    for(auto [c,u,v]:vec) {
        if(UF.same(u,v)) continue;
        ans += c;
        UF.merge(u,v);
    }
    auto g = UF.groups();
    if(g.size() != 1) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}