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
    ll mn = 0;
    ll sm = 0;
    rep(i,N) {
        cin >> U[i] >> D[i];
        chmax(mn, U[i] + D[i]);
        sm += U[i] + D[i];
    }
    auto judge = [&] (ll c) -> bool {        
        ll L = 0, R = INF;
        rep(i,N) {
            if(D[i] + U[i] < c) {
                return false;
            }
            L = max(L-X, (ll)0);
            L = max(L, c-D[i]);
            R = min(U[i], R+X);
            if(R < L){
                return false;
            }
        }
        return true;
    };

    ll ok = 0, ng = mn + 1;
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