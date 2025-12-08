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
    ll N,C; cin >> N >> C;
    vector D(C, vector<ll>(C));
    rep(i,C) rep(j,C) cin >> D[i][j];
    vector<vector<ll>> A(N, vector<ll>(N));
    rep(i,N) rep(j,N) cin >> A[i][j], A[i][j]--;
    vector<map<ll,ll>> mp(3);
    rep(i,N) rep(j,N){
        mp[(i+j)%3][A[i][j]]++;
    }
    ll ans = INF;
    rep(c1,C) rep(c2,C) rep(c3,C){
        if(c1 == c2 || c2 == c3 || c1 == c3) continue;
        vector<ll> cc(3);
        cc[0] = c1; cc[1] = c2; cc[2] = c3;
        ll tmp = 0;
        rep(k,3) {
            for(auto [col, cnt]: mp[k]){
                tmp += D[col][cc[k]] * cnt;
            }
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}