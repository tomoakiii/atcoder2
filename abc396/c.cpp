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
    vector<ll> B(N), W(M);
    rep(i,N) cin>>B[i];
    rep(i,M) cin>>W[i];

    sort(B.rbegin(), B.rend());
    sort(W.rbegin(), W.rend());
    rep(i,N-1) {
        B[i+1] += B[i];
    }
    ll mx = 0, sm = 0;
    int p = min(N,M);
    rep(i,p) {
        ll sm_new;
        sm_new = sm + W[i];
        chmax(mx, B[i] + sm_new);
        chmax(mx, B[i] + sm);
        chmax(sm, sm_new);
    }
    for(int i = p; i < N; i++) {
        chmax(mx, B[i] + sm);
    }
    cout << mx << endl;
    return 0;
}
