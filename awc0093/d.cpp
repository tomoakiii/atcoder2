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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> H(N);
    rep(i,N) cin>>H[i];
    auto H2=H;
    sort(H2.begin(),H2.end());
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    ll ok=N-1,ng=-1;
    auto bfs=[&](ll X)->bool{
        if(H[0]>X || H[N-1]>X) return false;
        vector<ll> dist(N,INF);
        dist[0]=0;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            auto q=que.front();
            que.pop();
            for(auto nx:uv[q]){
                if(H[nx]>X) continue;
                if(chmin(dist[nx], dist[q]+1)) que.push(nx);
            }
        }
        if(dist[N-1]<K) return true;
        return false;
    };
    if(!bfs(H2[N-1])){
        cout<<-1<<endl;
        return 0;
    }
    while(ok-ng>1){
        ll c=(ok+ng)/2;
        if(bfs(H2[c])) ok=c;
        else ng=c;
    }
    cout<<H2[ok]<<endl;
    return 0;
}