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
    ll N; cin >> N;
    vector<ll> A(N);
    ll hmx = 0;
    rep(i,N) {
        cin>>A[i];
        chmax(hmx, A[i]);
    }
    vector Grid(hmx+1, vector<ll>(N+1));
    rep(i,N) rep(j,hmx+1) {
        if(A[i] > j) Grid[j][i] = 1;
    }
    ll ans = 0;

    rep(i,hmx+1) {
        bool f = false;
            rep(j,N+1) {
            if(!f && Grid[i][j] == 1) {
                f = true;
                ans++;
            } else if (f && Grid[i][j] == 0) {
                f = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}