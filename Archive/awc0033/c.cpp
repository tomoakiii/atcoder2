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
    ll N,M,K,T;
    cin >> N >> M >> K >> T;
    vector<bool> C(N);
    rep(i,K){
        ll c;
        cin>>c;
        c--;
        C[c] = true;
    }
    vector<ll> P(N);
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
        if(C[u])P[v]++;
        if(C[v])P[u]++;
    }
    queue<int>que;
    rep(i,N) if(P[i]>=T && !C[i]) {
        C[i]=true; que.push(i);
    }
    while(!que.empty()) {
        auto i=que.front();
        que.pop();
        for(auto nx:uv[i]) {
            P[nx]++;
            if(!C[nx] && P[nx]>=T) {
                que.push(nx);
                C[nx]=true;
            }
        }
    }
    ll ans=0;
    rep(i,N)if(C[i])ans++;
    cout<<ans<<endl;
    return 0;
}