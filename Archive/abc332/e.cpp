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
typedef long double ld;

struct math{
    ld u;
    ld xsm;
    ld x2sm;
    ld std;
    ld n;
};

int main(){
    int N, D; cin>>N>>D;
    vector<ll> W(N);
    rep(i,N) cin>>W[i];
    vector<ll> grp;
    ld ans = 1e20;
    auto dfs = [&](auto dfs, int cur)->void{
        if (cur == N) {
            if(grp.size() != D) return;
            ld u = 0;
            for(auto m:grp) {
                u += m;
            }
            u /= D;
            ld std = 0;
            for(auto m:grp) {
                std += (m - u) * (m - u);
            }
            std /= D;
            chmin(ans, std);
            return;
        }
        int rem = N - cur - 1;
        if(grp.size() + rem >= D) {
            rep(i,grp.size()) {
                grp[i] += W[cur];
                dfs(dfs, cur+1);
                grp[i] -= W[cur];
            }
        }
        if(grp.size()==D) return;
        grp.push_back(W[cur]);
        dfs(dfs, cur+1);
        grp.pop_back();
    };
    dfs(dfs, 0);
    printf("%.20Lf\n", ans);
    return 0;
}