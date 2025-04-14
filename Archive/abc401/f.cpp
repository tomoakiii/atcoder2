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
    ll N, N2;    
    cin >> N;
    vector<vector<ll>> uv(N);
    rep(i, N-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    cin >> N2;
    vector<vector<ll>> uv2(N2);
    rep(i, N2-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv2[u].emplace_back(v);
        uv2[v].emplace_back(u);
    }

    vector<bool> visit11(N), visit12(N), visit13(N), visit21(N2), visit22(N2), visit23(N2);
    int mx = -1;
    vector<ll> dist(N), dista(N), distb(N), dist2(N2), dista2(N2), distb2(N2);
    auto longest = [&mx](auto longest, int cur, int d, int lp, vector<vector<ll>>& uv, vector<ll>& dist, vector<bool>& visit)-> int{
        visit[cur] = true;
        dist[cur] = d;
        if(mx < d) {
            mx = d;
            lp = cur;
        }
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;
            lp = longest(longest, nx, d+1, lp, uv, dist, visit);
        }
        return lp;
    };
    int pa = longest(longest, 0, 0, 0, uv, dist, visit11);
    mx = -1; int pb = longest(longest, pa, 0, 0, uv, dista, visit12);    
    mx = -1; longest(longest, pb, 0, 0, uv, distb, visit13);
    // --------------
    mx = -1; int pa2 = longest(longest, 0, 0, 0, uv2, dist2, visit21);           
    mx = -1; int pb2 = longest(longest, pa2, 0, 0, uv2, dista2, visit22);
    mx = -1; longest(longest, pb2, 0, 0, uv2, distb2, visit23);
    // ---------------
    ll rd = max(distb[pa], distb2[pa2]);
    rep(i,N2) distb2[i] = max(dista2[i], distb2[i]);
    sort(distb2.begin(), distb2.end());
    vector sm = distb2;
    for(int i = N2-1; i>0; i--) sm[i-1] += sm[i];    
    ll ans = 0;
    rep(i,N) {
        ll m = max(dista[i], distb[i]);
        int id = lower_bound(distb2.begin(), distb2.end(), rd-m) - distb2.begin();
        if(id == N2) {
            ans += rd * N2;
        } else {
            ans += (N2-id) * (m+1) + sm[id];
            ans += id * rd;
        }
    }

    cout << ans << endl;
    return 0;
}