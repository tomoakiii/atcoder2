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
    ll N, D;
    cin >> N >> D;
    vector<ll> T(N), L(N);
    rep(i,N) cin>>T[i]>>L[i];
    for(int k=1; k<=D; k++) {
        ll mx = 0;
        rep(i, N) {
            chmax(mx, T[i]*(L[i]+k));
        }
        cout << mx << endl;
    }
    return 0;
}