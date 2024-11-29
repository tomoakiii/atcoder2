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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> S(N+1, 0);
    rep(i,N) {
        S[i+1] = A[i] + S[i];        

    }
    ll mx = -INF;
    ll tmx = 0;
    rep(i, M) {
        tmx += (i+1) * A[i];
    }
    chmax(mx, tmx);

    for(ll i=0; i<N-M; i++) {
        tmx -= (S[i+M] - S[i]);
        tmx += M * A[i+M];
        chmax(mx, tmx);
    }
    cout << mx << endl;
    return 0;
}