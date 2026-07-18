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
    ll N,M,K,Q,T;
    cin >> N >> M >> K >> Q >> T;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> dist(N,INF);
    vector<int> S(K);
    rep(i,K) {
        cin>>S[i];
        S[i]--;
    }
    vector<bool> fire(N);
    rep(i,Q) {
        int p; cin>>p; p--;
        fire[p] = true;
    }
    T--;
    dist[T]=0;
    queue<int> que;
    que.push(T);
    while(!que.empty()){
        auto q=que.front();
        que.pop();
        for(auto nx:uv[q]){
            if(fire[nx]) continue;
            if(chmin(dist[nx], dist[q]+1)) {
                que.push(nx);
            }
        }
    }
    ll ans = 0;
    for(auto s:S){
        if(fire[s] || dist[s]==INF) {
            cout<<-1<<endl;
            return 0;
        }
        chmax(ans, dist[s]);
    }
    cout<<ans<<endl;
    return 0;
}