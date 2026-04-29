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
    ll N;
    cin >> N;
    vector uv(N, vector<int>{});
    for(int i=1;i<N;i++) {
        int p; cin>>p; p--;
        uv[p].push_back(i);
    }
    vector<ll> W(N);
    rep(i,N)cin>>W[i];

    vector<ll> S(N);
    auto dfs= [&](auto dfs, int cur, int pre=-1)->void{
        for(auto nx : uv[cur]){
            if(nx==pre)continue;
            dfs(dfs,nx,cur);
            W[cur]+=W[nx];
        }
    };
    dfs(dfs,0);
    ll ans=0;
    rep(i,N) {
        if(uv[i].size()<=1)continue;
        ll mx=0, mn=INF;
        for(auto j:uv[i]){
            chmax(mx,W[j]);
            chmin(mn,W[j]);
        }
        chmax(ans,mx-mn);
    }
    cout<<ans<<endl;
    return 0;
}