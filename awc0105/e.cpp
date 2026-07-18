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

// y0 = x0 + k0 p0
// y1 = x1 + k1 p1
// g = gcd(p0, p1)
// (y0-y1) = (x0-x1) + g(k0 p0/g - k1 p1/g)
// when y0 = y1, then (x0-x1) + g(k0 p0/g - k1 p1/g) = 0
// (x0-x1) = g(k1 p1/g - k0 p0/g)
// (x0-x1) % g = 0
// therefore, to make all y0 = y1 = ... = yN-1, we need to check if (xi-xj) % gcd(pi, pj) == 0 for all i,j
 // in order to avoid the O(N^2) time complexity, we can check if (xi-xj) % gcd(pi, pj) == 0 for all i,j by checking if (xi-xj) % g == 0 for all i,j, where g = gcd(p0, p1, ..., pN-1)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,T;
    cin >> N >> T;
    vector<ll> X(N),P(N);
    map<ll,ll> mp;
    bool possible = true;
    rep(i,N) {
        cin>>X[i]>>P[i];
        if(mp.contains(P[i])) {
            ll j = mp[P[i]];
            if(X[i] < j){
                if(X[i] % j != 0) {
                    possible = false;
                }
            } else {
                if(j % X[i] != 0) {
                    possible = false;
                }
            }
            mp[P[i]] = min(j, X[i]);
        } else {
            mp[P[i]] = X[i];
        }
    }
    ll g = 0;
    rep(i,N) g = gcd(g, P[i]);
    rep(i,N) {
        if ((X[i] - X[0]) % g != 0) {
            possible = false;
            break;
        }
        if (!possible) break;
    }
    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}