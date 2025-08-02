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
typedef pair<ll,int> pli;
int main(){
    ll N,M,X,Y;
    cin >> N >> M >> X >> Y;
    X--, Y--;
    struct ST{
        int to;
        ll K, T;
    };
    vector uv(N, vector<ST>{});
    rep(i,M) {
        int u,v;
        ll t,k;
        cin>>u>>v>>t>>k;
        u--, v--;
        ST st;
        st.to = v; st.T = t; st.K = k;
        uv[u].emplace_back(st);
        st.to = u;
        uv[v].emplace_back(st);
    }
    vector<ll> T(N, INF);
    T[X] = 0;

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0,X});
    while(!pq.empty()){
        auto [t, u] = pq.top();
        pq.pop();
        if(T[u] < t) continue;
        for(auto st: uv[u]){
            ll p = (t+st.K-1)/st.K;
            ll ts = p * st.K;
            ll ta = ts + st.T;
            if(T[st.to] > ta) pq.push({ta, st.to});
            chmin(T[st.to], ta);
        }
    }
    if(T[Y]==INF) cout<<-1<<endl;
    else cout<<T[Y]<<endl;
    return 0;
}