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
    ll N, K;
    cin >> N >> K;
    vector<int> P(N);
    vector<int> Ord(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
        Ord[P[i]] = i;
    }

    // A[0] - A[1]
    vector id(N, vector<int>{});
    int idn = -1;
    map<int, pair<int, int>> mp;
    vector<int> ans(N, -1);
    rep(i,N) {
        auto it = mp.lower_bound(P[i]);
        if (it == mp.end()) {
            idn++;
            mp[P[i]] = {1, idn};            
            id[idn].push_back(P[i]);
        } else {
            auto [cnt, tidn] = it->second;
            mp.erase(it);
            mp[P[i]] = {cnt+1, tidn};
            id[tidn].push_back(P[i]);
        }
        auto [cnt, tidn] = mp[P[i]];
        if (cnt == K) {            
            for(auto j: id[tidn]) {
                ans[j] = i+1;
            }
            mp.erase(P[i]);
        }
    }
    rep(i,N) cout<<ans[i]<<endl;

    return 0;
}