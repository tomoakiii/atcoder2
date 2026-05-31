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
typedef pair<ll,ll> pli;
int main(){
    ll H,W,N;
    cin >> H >> W >> N;
    map<ll, vector<pli>> mp;
    map<pli, int> id;
    rep(i,N) {
        ll r,c,a;
        cin>>r>>c>>a;
        r--, c--;
        a*=-1;
        mp[a].push_back({r,c});
        id[{r,c}] = i;
    }
    
    vector<int> rows(H,-1), cols(W,-1);
    vector<int> ans(N);
    for(auto [a, rc] : mp) {        
        for (auto [r, c]: rc) {
            ans[id[{r,c}]] = max(rows[r], cols[c]) + 1;
        }
        for (auto [r, c]: rc) {
            chmax(rows[r], ans[id[{r,c}]]);
            chmax(cols[c], ans[id[{r,c}]]);
        }
    }
    rep(i,N) cout<<ans[i]<<endl;
    return 0;
}