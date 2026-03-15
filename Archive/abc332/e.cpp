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

int main(){
    int N, D; cin>>N>>D;
    vector<ll> W(N);
    ld sm=0;
    rep(i,N) {
        cin>>W[i];
        sm += W[i];
    }
    sort(W.rbegin(),W.rend());
    vector<ll> grp;
    ll tmpmn = 3LL<<60;
    auto dfs = [&](auto dfs, int cur, ll sm2)->void{
        if(sm2 > tmpmn) return;
        if(cur == N) {
            chmin(tmpmn, sm2);
            return;
        }

        if(grp.size()<D) {
            grp.push_back(W[cur]);
            dfs(dfs, cur+1, sm2+W[cur]*W[cur]);
            grp.pop_back();
        }

        rep(i,grp.size()) {
            ll ps = grp[i]*grp[i];
            grp[i] += W[cur];
            dfs(dfs, cur+1, sm2-ps+grp[i]*grp[i]);
            grp[i] -= W[cur];
        }
    };
    grp.push_back(W[0]);
    dfs(dfs, 1, W[0]*W[0]);
    ld d2 = tmpmn;
    ld d = D;
    ld ans = (d2 * d - sm * sm)/(d*d);
    printf("%.20Lf\n", ans);
    return 0;
}