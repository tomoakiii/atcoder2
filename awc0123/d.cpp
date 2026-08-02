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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    vector<ll> vuc(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        vuc[v]++;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i,N) {
        if(vuc[i]==0) pq.push(i);
    }
    vector<ll> ans;
    while(!pq.empty()) {
        ll v = pq.top(); pq.pop();
        ans.emplace_back(v);
        for(auto u:uv[v]) {
            vuc[u]--;
            if(vuc[u]==0) pq.push(u);
        }
    }
    if(ans.size()!=N) {
        cout << -1 << endl;
        return 0;
    }
    for(auto x:ans) cout << x+1 << " ";
    cout << endl;
    return 0;
}