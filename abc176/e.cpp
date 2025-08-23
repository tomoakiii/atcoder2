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
    ll H,W,M;
    cin >> H >> W >> M;
    map<ll,ll> mpH, mpW;
    ll mxh=0, mxw=0;
    vector<set<ll>> vH(3*100000 + 1);
    rep(i,M) {
        ll h, w; cin >> h >> w;
        mpH[h]++; mpW[w]++;
        vH[h].insert(w);
        chmax(mxh, mpH[h]);
        chmax(mxw, mpW[w]);
    }
    vector<ll> vh, vw;
    for(auto m: mpH) {
        if(m.second == mxh) {
            vh.push_back(m.first);
        }
    }
    for(auto m: mpW) {
        if(m.second == mxw) {
            vw.push_back(m.first);
        }
    }
    for(auto v: vh) {
        
    }
    cout << p1 + p2 - 1 << endl;
    return 0;
}