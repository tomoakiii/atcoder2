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

<<<<<<< HEAD
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];

    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
=======
// y0 = x0 + k0 p0
// y1 = x1 + k1 p1
// g = gcd(p0, p1)
// (y0-y1) = (x0-x1) + g(k0 p0/g - k1 p1/g)
// when y0 = y1, then (x0-x1) + g(k0 p0/g - k1 p1/g) = 0
// (x0-x1) = g(k1 p1/g - k0 p0/g)
// (x0-x1) % g = 0
// therefore, to make all y0 = y1 = ... = yN-1, we need to check if (xi-xj) % gcd(pi, pj) == 0 for all i,j
// in order to avoid the O(N^2) time complexity, we can check if (xi-xj) % gcd(pi, pj) == 0 for all i,j by checking if (xi-xj) % g == 0 for all i,j, where g = gcd(p0, p1, ..., pN-1)
// but the combination of i,j is still O(N^2), so we can check if (xi-xj) % g == 0 for all i,j by checking if (xi-x0) % g == 0 for all i, where x0 is the first element of X// oh no, we forgot the exception case where (k1 p1/g - k0 p0/g) = 0. In this case, the condition to make y0 = y1 is (x0-x1) = 0, which means x0 = x1. Therefore, we need to check if (xi-xj) % g == 0 for all i,j, and if (k1 p1/g - k0 p0/g) = 0, then we need to check if xi = xj for all i,j. But we can check if (xi-xj) % g == 0 for all i,j by checking if (xi-x0) % g == 0 for all i, and we can check if xi = xj for all i,j by checking if xi = x0 for all i. Therefore, we can check if (xi-x0) % g == 0 for all i, and if (k1 p1/g - k0 p0/g) = 0, then we can check if xi = x0 for all i. If both conditions are satisfied, then it is possible to make all yi equal. Otherwise, it is not possible.

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
>>>>>>> 762c96cd907c5c0e9074087b1e61f9c27f58aeb4
    }
    return 0;
}