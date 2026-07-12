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
    vector<double> W(N);
    vector<pair<ll,int>> Hs(N);
    rep(i,N) {
        cin>>H[i];
        Hs[i].first=H[i];
        Hs[i].second=i;
    }
    vector<double> Hd(N);
    rep(i,N) cin>>W[i];
    sort(Hs.rbegin(),Hs.rend());
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<bool> dam(N);
    rep(i,K){
        int s; cin>>s; s--;
        dam[s] = true;
    }
    for(auto [h,i]:Hs){
        Hd[i] += W[i];
        if(dam[i]) continue;
        vector<int> v;
        for(auto nx:uv[i]){
            if(H[nx] >= H[i]) continue;
            v.push_back(nx);
        }
        if(v.empty()) continue;
        double w = v.size();
        for(auto u:v){
            Hd[u] += Hd[i] / w;
        }
        Hd[i] = 0;
    }
    rep(i,N) {
        printf("%.10f%c", Hd[i], " \n"[i==N-1]);
    }
    return 0;
}