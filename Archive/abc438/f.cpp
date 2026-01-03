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

ll nc2(ll x){
    return x * (x-1) / 2;
}

int main(){
    ll N;
    cin >> N;
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }

    vector<ll> par(N);
    vector<ll> cld(N);
    vector<ll> dpt(N, 0);
    auto dfs = [&](auto dfs, int cur, int pre = -1)->ll{
        ll ret = 1;
        par[cur] = pre;
        if(pre != -1) dpt[cur] = dpt[pre] + 1;
        for(auto nx: uv[cur]){
            if(nx == pre) continue;
            ret += dfs(dfs, nx, cur);
        }
        cld[cur] = ret;
        return ret;
    };
    dfs(dfs, 0);
    vector<ll> visit(N);
    unordered_set<ll> st;
    ll l=-1,r=-1;
    bool ok = true;
    ll ans = 0;
    ll lsm = 0;
    rep(i,N) {
        if(visit[i]) {
            if(st.contains(i)) {
                st.erase(i);
            }
        } else {
            int p = i, pr = -1;
            while(!visit[p]) {
                visit[p] = true;
                st.insert(p);
                pr = p;
                p = par[p];
            }
            if(p == 0) {
                if(l == -1) {
                    l = i;
                    lsm = cld[pr];
                } else if {
                    (r == -1) r = i;
                }
                else {
                    ok = false;
                    break;
                }
            } else if (p == l) {
                ans += (i-1) * (dpt[i] - dpt[l] - 1);
                ans += i;
                l = i;
            } else if (p == r) {
                ans += (i-1) * (dpt[i] - dpt[r] - 1);
                ans += i;
                r = i;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
