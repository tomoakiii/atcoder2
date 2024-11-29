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
typedef modint998244353 mint;
int main(){
    ll N, M;
    vector<ll> dy(3), dx(3);
    cin >> N >> M >> dx[0] >> dy[0] >> dx[1] >> dy[1] >> dx[2] >> dy[2];
    set<pair<ll, ll>> blk;
    rep(i,M) {
        ll x, y;
        cin >> x >> y;
        blk.insert({x,y});
    }
    vector<bool> dlt(3, false);
    /*
        for(int i=0; i<=1; i++) for(int j=i+1; j<3; j++) {
            if (dx[i] == dx[j] && dy[i] == dy[j] ) {
                dlt[i] = true;
            }
        }
        for(int i=2; i>=0; i--) {
            if(dlt[i]) {
                dy.erase(dy.begin()+i);
                dx.erase(dx.begin()+i);
            }
        }
    */
    map<pair<ll, ll>, mint> mp;
    mp[{0,0}] = 1;
    rep(i, N) {
        map<pair<ll, ll>, mint> mp2;
        for(auto m: mp) {
            rep(j, dy.size()){
                pair<ll, ll> np = {m.first.first + dx[j], m.first.second + dy[j]};
                if (blk.count(np) == 0) mp2[np] += m.second;
            }
        }
        swap(mp2, mp);
    }
    mint ans = 0;
    for(auto m: mp) {
        ans += m.second;
    }

    cout << ans.val() << endl;
    return 0;
}