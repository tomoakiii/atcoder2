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
    vector F(N, vector<ll>(10));
    vector P(N, vector<ll>(11));

    rep(i,N)rep(j,10) cin>>F[i][j];
    rep(i,N)rep(j,11) cin>>P[i][j];

    ll M = 1<<10;
    ll ans = -INF;
    for(ll m = 1; m < M; m++) {
        vector<ll> cnt(N,0);
        rep(j, 10) {
            if((m>>j) & 1 > 0) {
                rep(i, N){
                    if(F[i][j]) cnt[i]++;
                }
            }
        }
        ll t = 0;
        rep(i,N) {
            t += P[i][cnt[i]];
        }
        chmax(ans, t);
    }
    cout<<ans<<endl;
    return 0;
}