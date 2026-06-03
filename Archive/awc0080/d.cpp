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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<tuple<ll, int,int>> uvw(M);
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uvw[i] = make_tuple(w,u,v);
    }
    dsu UF(N);
    ll ans=0;
    rep(i,K){
        int e; cin>>e; e--;
        auto [w,u,v] = uvw[e];
        if(UF.same(u,v)) {
            cout<<-1<<endl;
            return 0;
        }
        UF.merge(u,v);
        ans+=w;
        uvw[e] = make_tuple(INF,-1,-1);
    }
    sort(uvw.begin(), uvw.end());
    rep(i,M-K){
        auto [w,u,v] = uvw[i];
        if(UF.same(u,v)) {
            continue;
        }
        UF.merge(u,v);
        ans+=w;
    }
    rep(i,N){
        if(!UF.same(0,i)) {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}