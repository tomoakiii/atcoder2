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
    cin >> N;
    vector<ll> P(N,-1);
    rep(i,N-1) {
        ll p; cin>>p; p--;
        P[i+1]=p;
    }
    vector<ll> C(N),W(N);
    rep(i,N) cin>>C[i]>>W[i];
    ll ans=N-1;
    vector uv(N, vector<int>{});
    vector<ll> weg(N);
    vector<unordered_set<int>> vst(N);
    for(int i=1;i<N;i++){
        int p=P[i];
        ll w=min(W[i],W[p]);
        ans+=w;
        weg[i] = w;
        vst[p].insert(i);
        uv[p].push_back(i);
    }
    auto dfs=[&](auto dfs, int cur)->void{
        int p=P[cur];
        for(auto nx:uv[cur]){
            dfs(dfs, nx);
            if(vst[cur].contains(nx)) {
                C[cur]--;
            }
        }
        if(p!=-1){
            if(C[cur] > 0) {
                ans -= weg[cur];
                C[cur]--;
                vst[p].erase(cur);
            }
        }
    };
    dfs(dfs,0);
    cout<<ans<<endl;
    return 0;
}