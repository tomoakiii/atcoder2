#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    ll thr = sqrt(2*M);
    vector uv_big(N, vector<ll>{});
    vector<bool> isbig(N);
    rep(i,N) if(uv[i].size()>=thr) isbig[i] = true;
    rep(i,N) {
        for(auto nx: uv[i]) {
            if(isbig[nx]) uv_big[i].push_back(nx);
        }
    }
    ll Q; cin>>Q;
    vector<pair<int,ll>> xy(Q);
    vector<ll> ans(Q,-1);
    vector<ll> col(N,1);
    vector<int> upd(N,-1);
    rep(i,Q) {
        int x; ll y; cin>>x>>y; x--;
        xy[i] = {x,y};

        if(isbig[x]) ans[i] = col[x];
        else {
            bool flg = true;
            int last = -1;
            chmax(last, upd[x]);
            for(auto nx: uv[x]) {
                chmax(last, upd[nx]);
            }
            if(last == -1) ans[i] = 1;
            else ans[i] = xy[last].second;
        }
        col[x] = y;
        for(auto nx: uv_big[x]) {
            col[nx] = y;
        }
        upd[x] = i;
    }
    rep(i,Q) cout<<ans[i]<<endl;
    return 0;
}