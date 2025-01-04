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

struct dcs{
    int D, C;
    ll S;
    const bool operator<(const dcs *x) const {
        return (D < x.D);
    };
}

int main(){
    int N;
    cin >> N;
    vector<dcs> vt(N);
    rep(i,N) {
        cin >> vt[i].D >> vt[i].C >> vt[i].S;
    }
    sort(vt.begin(), vt.end());
    vector dp(5001, vector<ll>(5001));
    rep(i, N) {
        rep(j, D-C) {
            if()
        }
    }
    return 0;
}