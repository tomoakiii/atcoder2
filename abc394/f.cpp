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
typedef pair<ll, bool> pib;
int main(){
    ll N;
    cin >> N;
    vector uv(N, vector<ll>{});

    rep(i,N-1) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        uv[a].push_back(b);
        uv[b].push_back(a);
    }
    ll ans = -1;
    auto func = [&](auto func, int cur, int pre)->pib{
        pib out;
        out.first = 0;
        if(uv[cur].size() >= 4) {
            vector<ll> sz{};
            for(auto nx: uv[cur]) {
                if(nx==pre) continue;
                auto [s, b] = func(func, nx, cur);
                sz.push_back(s);
            }
            sort(sz.rbegin(), sz.rend());
            rep(i,3) {
                out.first += sz[i];
            }
            if(sz.size() >= 4) {
                chmax(ans, out.first + 1 + sz[3]);
            }
            out.first += 1;
            out.second = true;
            
            return out;        
        } else {
            for(auto nx: uv[cur]) {
                if(nx==pre) continue;
                auto [s, b] = func(func, nx, cur);
                if(b) {
                    chmax(ans, s + 1);
                }
            }
            out.first = 1;
            out.second = false;
            return out;
        }
    };
    rep(i,N-1) {
        if(uv[i].size() == 1) {
            func(func, i, -1);
            break;
        }
    }
    cout << ans << endl;

    return 0;
}