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
typedef pair<ll, ll> pll;
const ll OFFS = 2 * 10e9;

int main(){
    ll N;
    cin >> N;
    vector<ll> X(N+1), P(N+1);
    rep(i,N) {
        cin>>X[i+1];
        X[i+1] += OFFS;
    }
    rep(i,N) cin>>P[i+1];
    for(int i=1; i<=N; i++) {
        P[i] += P[i-1];
    }

    int Q;
    cin >> Q;
    while(Q--){
        ll l, r;
        cin >> l >> r;
        l += OFFS;
        r += OFFS;
        auto il = lower_bound(X.begin(), X.end(), l);
        int ild = il - X.begin() - 1;
        auto iu = upper_bound(X.begin(), X.end(), r);
        int iud = iu - X.begin() - 1;
        cout << P[iud] - P[ild] << endl;
    }


    return 0;
}