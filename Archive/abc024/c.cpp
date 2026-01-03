#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
template <typename T>
inline bool chmax(T& a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T& a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main() {
    int N, D, K;
    cin >> N >> D >> K;
    vector<ll> L(D),R(D);
    rep(i,D) cin>>L[i]>>R[i];
    rep(i,K) {
        ll s, t; cin>>s>>t;
        if(t > s){
            rep(j,D) {
                if(L[j] <= s && s <= R[j]) {
                    s = R[j];
                }
                if(s >= t) {
                    cout << j+1 << endl;
                    break;
                }
            }
        } else {
            rep(j,D) {
                if(L[j] <= s && s <= R[j]) {
                    s = L[j];
                }
                if(s <= t) {
                    cout << j+1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}