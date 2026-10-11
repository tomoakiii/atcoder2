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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];

    vector uv(N+1, vector<pair<ll,ll>>{});
    rep(i,N){
        int j = (i+1)%N;
        uv[j].push_back({i,A[i]});
        uv[i].push_back({j,A[i]});
        uv[i].push_back({N,B[i]});
        uv[N].push_back({i,B[i]});
    }

    vector<ll> dist(N+1,INF);
    dist[N]=0;
    typedef pair<ll,ll> pll;
    priority_queue<pll, vector<pll>, greater<pll>> que;
    que.push({0,N});
    while(!que.empty()){
        auto [w,i] = que.top();
        que.pop();
        if(dist[i]<w)continue;
        for(auto [nx, w] : uv[i]){
            if(chmin(dist[nx], dist[i]+w)) que.push({dist[nx],nx});
        }
    }

    vector<ll> Asm(2*N+1);
    rep(i,N+N)Asm[i+1]=Asm[i]+A[i%N];

    while(Q--){
        int S,T; cin>>S>>T;
        S--,T--;
        if(T==N){
            cout<<dist[S]<<endl;
            continue;
        }
        ll ans = Asm[T]-Asm[S];
        chmin(ans, Asm[S+N]-Asm[T]);
        chmin(ans, dist[S] + dist[T]);
        cout<<ans<<endl;
    }
    return 0;
}