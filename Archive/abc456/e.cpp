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

void solve(){
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
    rep(i,N) uv[i].emplace_back(i);
    int W; cin>>W;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    /*
    vector visit(W, vector<bool>(N));
    vector<int> judge(N); // 0 not yet, 1 passed, 2 loop
    */
    scc_graph G(N*W);

    auto toInd=[&N](ll i, ll j)->ll{
        return i + N*j;
    };
    auto toIJ=[&N](ll x)->pair<int,int>{
        int i = x%N;
        int j = x/N;
        return {i,j};
    };
    rep(i,N) {
        for(auto nx:uv[i]){
            rep(j,W) {
                int nj = (j+1)%W;
                if(S[i][j] == 'x') continue;
                if(S[nx][nj] == 'x') continue;
                ll u = toInd(i,j);
                ll v = toInd(nx,nj);
                //cerr<<i<<" "<<j<<"---"<<nx<<" "<<nj<<endl;
                G.add_edge(toInd(i,j), toInd(nx,nj));
                //G.add_edge(toInd(nx,nj), toInd(i,j));
            }
        }
    }
    for(auto gv: G.scc()) {
        ll s = gv.size();
        if(s <= 1) continue;
        for(auto g:gv) {
            auto [i,j] = toIJ(g);
            /*
            cerr<<i<<"-"<<j<<" --> ";
            */
            if(j==0) {
                cout<<"Yes"<<endl;
                return;
            }
        }
    }

    cout<<"No"<<endl;
}


int main(){
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}