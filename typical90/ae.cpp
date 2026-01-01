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
    int N,W,B;
    cin >> N >> W >> B;
    vector<ll> WV(N), BV(N);
    rep(i,N) cin>>WV[i];
    rep(i,N) cin>>BV[i];
    rep(i,N) {
        ll w = WV[i];
        ll b = BV[i] + w*W;

    }

    return 0;
}