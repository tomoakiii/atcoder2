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
    ll N, X;
    cin >> N >> X;
    vector<ll> U(N), D(N);
    ll mx = 0;
    ll sm = 0;
    rep(i,N) {
        cin >> U[i] >> D[i];
        chmax(mx, U[i] + D[i]);
        sm += U[i] + D[i];
    }
    auto judge = [&] (ll c) -> bool {
        ll L = U[0] - (U[0] + D[0] - c), R = U[0];
        for(int i = 1; i < N; i++) {
            L -= X;
            R += X;
            ll d = U[i] - (U[i] + D[i] - c);
            if(d < L || U[i] > R) {
                return false;
            }
            L = max(L, d);
            R = min(R, U[i]);
        }
        return true;
    };

    ll ok = 0, ng = mx + 1;
    while(ng - ok > 1) {
        ll c = (ok + ng) / 2;
        if(judge(c)) {
            ok = c;
        } else {
            ng = c;
        }
    }
    cout << sm - (N*ok) << endl;

    return 0;
}