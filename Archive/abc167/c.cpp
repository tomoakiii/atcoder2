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
    ll N,M,X;
    cin >> N>>M>>X;
    vector<ll> C(N);
    vector A(N, vector<ll>(M));
    rep(i,N){
        cin >> C[i];
         rep(j,M) cin>>A[i][j];
    }
    ll ans = INF;
    rep(k, 1<<N) {
        vector<ll> sc(M);
        ll sm = 0;
        rep(i,N) {
            if(k>>i & 1) {
                sm += C[i];
                rep(j,M) sc[j] += A[i][j];
            }
        }
        bool flg = true;
        rep(j,M) if(sc[j]<X) flg = false;
        if(flg) {
            chmin(ans, sm);
        }
    }
    if(ans < INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}