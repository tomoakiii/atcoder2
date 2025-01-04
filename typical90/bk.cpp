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
    int H, W;
    cin >> H >> W;
    vector P(H, vector<int>(W, 0));
    rep(i,H) rep(j,W) {
        cin>>P[i][j];
        P[i][j]--;
    }
    map<int, set<int>> lst;
    vector D(H*W, vector<int>(1<<8));
    rep(j, W) {
        map<int, int> mp;
        rep(i, H) {
            mp[P[i][j]] |= 1<<i;
        }
        for(auto m: mp) {
            D[m.first][m.second]++;
            lst[m.first].insert(m.second);
        }
    }
    ll ans = 0;
    for(auto m: lst) {
        int i = m.first;
        rep(k, 1<<8) {
            ll a = 0;
            for(auto j: lst[i]){
                if((k&j) != k) continue;
                a += D[i][j];
            }
            chmax(ans, a * popcount((uint)k));
        }
    }
    cout << ans << endl;
    return 0;
}