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
    ll N, M, K, T;
    cin >> N >> M >> K >> T;
    set<ll> clist;
    clist.insert(0);
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v, w);
    }
    vector S(K, vector<ll>{});
    vector<ll> P(K);
    rep(i,K){
        ll e; cin>>e;
        rep(j,e){
            ll s; cin>>s;
            s--;
            S[i].push_back(s);
            clist.insert(s);
        }
        cin>>P[i];
    }
    int sz = clist.size();
    map<int,int> cindex;
    int idx = 0;
    for(auto c: clist){
        cindex[c] = idx++;
    }
    vector dists(sz, vector<ll>(sz, INF));
    for(auto st:clist){
        vector<ll> dist(N, INF);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        dist[st] = 0;
        pq.push({0, st});
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            if(d > dist[u]) continue;
            for(auto [v, w]: uv[u]){
                if(chmin(dist[v], dist[u] + w)){
                    pq.push({dist[v], v});
                }
            }
        }
        for(auto c:clist){
            dists[cindex[st]][cindex[c]] = dist[c];
        }
    }
    ll ful = 1ll<<sz;
    vector dp(ful, vector<ll>(sz, INF));
    dp[1][0] = 0;
    rep(S,ful){
        rep(from,sz){
            if(dp[S][from] == INF) continue;
            if((S>>from)&1 == 0) continue; 
            rep(to,sz){
                ll nS = S | (1ll<<to);
                chmin(dp[nS][to], dp[S][from] + dists[from][to]);
            }
        }
    }
    vector<ll> indlist(K, 0);
    rep(i,K){
        for(auto s:S[i]){
            indlist[i] |= (1ll<<cindex[s]);
        }
    }
    ll ans = 0;
    rep(S,ful){
        ll mn = INF;
        rep(j,sz) chmin(mn, dp[S][j]);
        if(mn > T) continue;
        ll tmp = 0;
        rep(k,K){
            if( (S & indlist[k]) == indlist[k]) tmp += P[k];
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}