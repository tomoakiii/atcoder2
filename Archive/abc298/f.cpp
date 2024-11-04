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
    map<pair<ll,ll>, ll> Grid;
    map<ll, ll> Col, Row;
    vector<ll> R(N), C(N), X(N);
    rep(i, N) {
        ll r, c, x;
        cin >> r >> c >> x;
        r--, c--;
        R[i] = r;
        C[i] = c;
        X[i] = x;
        Grid[{r,c}] = x;
        Col[c] += x;
        Row[r] += x;
    }
    set<pair<ll, ll>> Cs, Rs;
    for(auto c: Col) {
        Cs.insert({c.second, c.first});
    }
    for(auto c: Row) {
        Rs.insert({c.second, c.first});
    }
        
    ll ans = 0;
    ll minc = 0;
    
    auto idr = Rs.rbegin();
    while(idr != Rs.rend()) {
        auto idc = Cs.rbegin();
        while(idc != Cs.rend()){
            auto [c1, c2] = *idc;
            if (c1 <= minc) break;
            if (Grid.count({(*idr).second, c2}) == 0) {
                chmax(ans, c1 + (*idr).first);
                minc = c1;
                continue;       
            } else {
                chmax(ans, c1 + (*idr).first - Grid[{(*idr).second, c2}]);
            }
            idc++;
        }        
        idr++;
    }
    cout << ans << endl;

    return 0;
}