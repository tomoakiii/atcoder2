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
    vector WH(1e5+1, vector<ll>{});
    rep(i,N) {
        ll h,w; cin>>h>>w;
        WH[h].push_back(w);
    }
    rep(h,1e5+1) {
        sort(WH[h].rbegin(), WH[h].rend());
    }
    ll ans = 0;
    vector<ll> P(N, INF);
    rep(h,1e5+1) {
        if(WH[h].empty()) continue;
        // auto P_new = P;
        for(auto w: WH[h]){
            auto it = lower_bound(P.begin(), P.end(), w) - P.begin();
            P[it] = w;
            chmax(ans, (ll)it+1);
        }
        // swap(P,P_new);
    }
    cout << ans << endl;
    return 0;
}