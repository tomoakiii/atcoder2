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
    vector<ll> P = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    vector<ll> cp(P.size(), 0);
    for(int i=1; i<=N; i++) {
        ll x = i;
        rep(j, P.size()) {
            ll p = P[j];
            while(x%p == 0) {
                x/=p;
                cp[j]++;
            }
        }
    }

    vector<ll> cnt(100,0);
    rep(i, P.size()) {
        rep(k, 100) {
            if(cp[i] >= k) cnt[k]++;
        }
    }
    ll ans = 0;
    rep(i,P.size()) {
        if(cp[i] >= 74) ans++; /* 75 */
        for(int j=i+1; j<P.size(); j++) {
            if(cp[i] >= 14 && cp[j] >= 4) ans++; /* 15,5 */
            if(cp[i] >= 24 && cp[j] >= 2) ans++; /* 25,3 */
            if(cp[i] >= 4 && cp[j] >= 14) ans++; /* 15,5 */
            if(cp[i] >= 2 && cp[j] >= 24) ans++; /* 25,3 */
            for(int k=j+1; k<P.size(); k++) {
                if(cp[i] >= 2 && cp[j] >= 4 && cp[k] >= 4) ans++; /* 3,5,5 */
                if(cp[i] >= 4 && cp[j] >= 2 && cp[k] >= 4) ans++;
                if(cp[i] >= 4 && cp[j] >= 4 && cp[k] >= 2) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}