#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<int,int> pii;
int main(){
    int N;
    cin >> N;
    vector A(N, vector<int>(N-1));
    map<pair<int,int>, int> mp;
    ll games = N * (N-1) / 2;
    int ind = 0;
    auto meet = [&](int i, int j)->pair<int,int> {
        return {min(i,j), max(i,j)};
    };

    vector<pair<int,int>> dict(games);
    rep(i,N) rep(j,N-1) {
        ll a; cin>>a; a--;
        A[i][j] = a;
        auto mt = meet(i,a);
        if(!mp.contains(mt)) {
            mp[mt] = ind;
            dict[ind] = mt;
            ind++;
        }
    }

    scc_graph G(games);
    vector uv(games, vector<int>{});
    rep(i,N) rep(j,N-2) {
        auto mt = mp[meet(i,A[i][j])];
        auto mt2 = mp[meet(i,A[i][j+1])];
        G.add_edge(mt, mt2);
        uv[mt].push_back(mt2);
    }

    ll ans = 0;
    vector<ll> dp(N*(N-1)/2, 1);
    for(auto gg: G.scc()) {
        if(gg.size()>1) {
            cout << -1 << endl;
            return 0;
        }
        if(gg.empty()) continue;
        for(auto c: uv[gg[0]]) {
            chmax(dp[c], dp[gg[0]] + 1);
            chmax(ans, dp[c]);
        }
    }
    cout<<ans<<endl;
    return 0;
}