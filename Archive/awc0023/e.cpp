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
    ll N,C;
    cin >> N >> C;
    vector<ll> W(N);
    rep(i,N) cin>>W[i];
    ll ans = N;
    vector<ll> grp{};
    auto dfs= [&](auto dfs, int cur)->void{
        if(cur==N) {
            chmin(ans, (ll)grp.size());
            return;
        }
        rep(i, grp.size()) {
            if(grp[i] + W[cur] <= C) {
                grp[i]+=W[cur];
                dfs(dfs, cur+1);
                grp[i]-=W[cur];
            }
        }
        if(grp.size()+1 >= ans) return;
        grp.push_back(W[cur]);
        dfs(dfs, cur+1);
        grp.pop_back();
    };
    dfs(dfs, 0);
    cout<<ans<<endl;
    return 0;
}