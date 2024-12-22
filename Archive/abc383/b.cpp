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
    ll H,W,D;
    cin >> H >> W >> D;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector<pair<int, int>> flr{};

    rep(i,H) rep(j,W) {
        if(S[i][j] == '.') {
            flr.push_back({i, j});
        }
    }

    int sz = (int)flr.size();
    ll mx = 0;
    rep(i,sz-1) for(ll j=i+1; j<sz; j++) {
        set<pair<int, int>> st;        
        rep(y,H) rep(x,W) {
            if(S[y][x] != '.') continue;
            if((abs(flr[i].first - y) + abs(flr[i].second - x)) <= D) st.insert({y, x});
            if((abs(flr[j].first - y) + abs(flr[j].second - x)) <= D) st.insert({y, x});
        }
        chmax(mx, (ll)st.size());
    }
    cout << mx << endl;
    return 0;
}