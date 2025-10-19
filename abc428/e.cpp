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
typedef pair<ll,ll> pll;
int main(){
    ll N, M;
    cin >> N;
    M = N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector vp(N, vector<pair<ll, pll>>{});
    auto dfs = [&](auto dfs, int cur, int pre, ll d)->pair<ll,int>{        
        ll mx = d;
        pair<ll,int> ret = {d, cur};
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            auto ret2 = dfs(dfs, nx, cur, d+1);
            auto [d2, mx_nd] = ret2;
            vp[cur].push_back({d2-d, {nx, mx_nd}});
            if(d2 >= mx) {
                ret = ret2;
            }
        }
        return ret;
    };
    dfs(dfs, 0, -1, 0);
    rep(i,N) sort(vp[i].rbegin(), vp[i].rend());
    vector<pair<ll,pair<int,int>>> ans(N);
    rep(i,N) {
        if(vp[i].size() > 0) ans[i] = vp[i][0];
        else ans[i] = {0, {i,i}};
    }
    rep(cur,N) {
        if(vp[cur].size()==0) continue;        


        auto [top_d, v2] = vp[cur][0];
        auto [top_nx, top_nd] = v2;
        
        ll second_d=-1;
        int second_nx=-1, second_nd=-1;
        if(vp[cur].size()>=2){
            auto vp2 = vp[cur][1];
            second_d = vp2.first;
            second_nx = vp2.second.first;
            second_nd = vp2.second.second;            
        } else {
            second_d = 0;
            second_nx = cur;
            second_nd = cur;
        }
        for(auto nx: uv[cur]) {
            if(nx != top_nx) {
                if(ans[nx].first < top_d + 1) {
                    ans[nx] = {top_d + 1, {cur, top_nd}};
                } else if (ans[nx].first == top_d + 1) {
                    if(top_nd > ans[nx].second.second) {
                        ans[nx] = {top_d + 1, {cur, top_nd}};
                    }
                }                
                
            } else  {
                if(ans[nx].first < second_d + 1) {
                    ans[nx] = {second_d + 1, {cur, second_nd}};
                } else if (ans[nx].first == second_d + 1) {
                    if(second_nd > ans[nx].second.second) {
                        ans[nx] = {second_d + 1, {cur, second_nd}};
                    }
                }
            }
            vp[nx].push_back(ans[cur]);
            sort(vp[nx].rbegin(), vp[nx].rend());
        }
        
    }
    rep(i,N) cout<<ans[i].second.second+1<<endl;
    return 0;
}