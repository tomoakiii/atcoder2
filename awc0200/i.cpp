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
    ll N,M,K,G,S,T;
    cin >> N >> M >> K >> G >> S >> T;
    vector<ll> P(N),Q(N);
    rep(i,N) cin>>P[i]>>Q[i];
    vector uv(N, vector<pair<ll,int>>{});
    vector<tuple<ll,ll,ll,ll,ll>> vt(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v; u--, v--;
        ll l, r, c, h, d;
        cin>>l>>r>>c>>h>>d;
        uv[u].emplace_back(v,i);
        vt[i] = make_tuple(l,r,c,h,d);
    }

    auto func = [&](ll U, ll V)->ll{
        vector dist(N, vector<ll>(K+1, INF));
        dist[0][S] = 0;
        typedef tuple<ll,ll,ll> tp;
        priority_queue<tp, vector<tp>, greater<tp>> que;
        que.push(make_tuple(0,0,S));
        while(!que.empty()){
            auto [dst, cur, height] = que.top();
            que.pop();
            if(dist[cur][height] < dst) continue;
            for(auto [nx, j] : uv[cur]){
                auto [l,r,c,h,d] = vt[j];
                for(int i = max(l,U); i <= min(r,V); i++) {
                    ll x=0;
                    if(i >= height) x+=(i-height)*P[cur];
                    if(i < height) x+=(height-i)*Q[cur];
                    ll y = c + d * abs(i-h);
                    if(chmin(dist[nx][i], dst + x + y)) {
                        que.push(make_tuple(dist[nx][i], nx, i));
                    }
                }
            }
        }
        ll ret = INF;
        for(ll i=U; i<=V; i++){
            ll d = dist[N-1][i];
            if(T>=i) chmin(ret, (T-i)*P[N-1] + d);
            if(T<i) chmin(ret, (i-T)*Q[N-1] + d);
        }
        return ret;
    };
    ll ans = INF;
    for(int u=0; u<=K; u++)for(int v=u; v<=K; v++){
        if(u > min(S,T) || v < max(S,T)) continue;
        ll f = func(u,v);
        cerr << u << " " << v << " " << f << endl;
        chmin(ans, f + G * (v-u));
    }
    if(ans==INF) cout<<"NA"<<endl;
    else cout<<ans<<endl;
    return 0;
}