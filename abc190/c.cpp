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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    rep(i,M) {
        cin>>A[i]>>B[i];
        A[i]--, B[i]--;
    }
    ll K; cin>>K;
    vector<ll> C(K), D(K);
    rep(i,K) {
        cin>>C[i]>>D[i];
        C[i]--, D[i]--;
    }
    ll mx = 0;
    rep(k,1<<K) {
        vector<bool> visit(N);
        rep(i, K) {
            if(k>>i & 1) {
                visit[C[i]] = true;
            } else {
                visit[D[i]] = true;
            }
        }
        ll ans = 0;
        rep(i,M) {
            if(visit[A[i]] && visit[B[i]]) ans++;
        }
        chmax(mx, ans);
    }
    cout << mx << endl;
    return 0;
}