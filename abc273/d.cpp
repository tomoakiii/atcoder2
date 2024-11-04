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
    ll H, W, rs, cs;    
    cin >> H >> W >> rs >> cs;
    map<ll, set<ll>> mpr, mpc;
    ll N;
    cin >> N;
    rep(i, N) {
        ll r, c;
        cin >> r >> c;        
        mpr[r].insert(c);
        mpc[c].insert(r);
    }
    for(auto &m:mpr) {
        m.second.insert(INF);
        m.second.insert(-INF);
    }
    for(auto &m:mpc) {
        m.second.insert(INF);
        m.second.insert(-INF);
    }
    ll Q;
    cin >> Q;
    while(Q--){
        char d;
        ll l;
        cin >> d >> l;
        if (d == 'L') {
            if (mpr[rs].empty()) {
                cs = cs - l;
            } else {
                auto id = mpr[rs].lower_bound(cs);
                id--;
                if((*id) + 1 < cs - l) cs = cs - l;
                else cs = (*id) + 1;
            }
        } else if (d == 'R') {
            if (mpr[rs].empty()) {
                cs = cs + l;
            } else {
                auto id = mpr[rs].lower_bound(cs);
                if ((*id) - 1 > cs + l) cs = cs + l;
                else cs = (*id) - 1;
            }
        } else if (d == 'U') {
            if (mpc[cs].empty()) {
                cs = cs - l;
            } else {
                auto id = mpc[cs].lower_bound(rs);
                id--;
                if((*id) + 1 < rs - l) rs = rs - l;
                else rs = (*id) + 1;
            }
        } else if (d == 'D') {
            if (mpc[cs].empty()) {
                cs = cs + l;
            } else {
                auto id = mpc[cs].lower_bound(rs);
                if ((*id) - 1 > rs + l) rs = rs + l;
                else rs = (*id) - 1;
            }
        }
        rs = max(rs, (ll)1);
        rs = min(rs, H);
        cs = max(cs, (ll)1);
        cs = min(cs, W);
        cout << rs << " " << cs << endl;
    }
    return 0;
}