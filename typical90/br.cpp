#include <bits/stdc++.h>
#include <atcoder/all>
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
    vector<ll> X(N,0), Y(N,0);
    rep(i,N) cin>>X[i]>>Y[i];
    sort(X.begin(), X.end());
    vector sX = X;
    rep(i,N-1) sX[i+1] += sX[i];
    sort(Y.begin(), Y.end());
    vector sY = Y;
    rep(i,N-1) sY[i+1] += sY[i];

    auto f = [&N](vector<ll> &v, vector<ll> &sm, int kit) -> ll {
        ll s = 0;
        rep(i, N) {
            s += abs(v[i] - v[kit]);
        }
        return s;
    };

    ll p1 = min(f(X, sX, N/2), f(X, sX, N/2 + 1));
    chmin(p1, f(X, sX, N/2-1));
    ll p2 = min(f(Y, sY, N/2), f(Y, sY, N/2 + 1));    
    chmin(p2, f(Y, sY, N/2-1));
    cout << p1 + p2 << endl;
    return 0;
}