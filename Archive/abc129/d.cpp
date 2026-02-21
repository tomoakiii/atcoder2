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
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector Wc(H+2, vector<ll>(W+2));
    vector Hc(H+2, vector<ll>(W+2));
    rep(i,H) rep(j,W) {
        if(S[i][j] == '#') {
            Hc[i+1][j+1] = 0;
            Wc[i+1][j+1] = 0;
        } else {
            Hc[i+1][j+1] = Hc[i][j+1] + 1;
            Wc[i+1][j+1] = Wc[i+1][j] + 1;
        }
    }
    ll ans = 0;
    for(int i=H; i>=1; i--) for(int j=W; j>=1; j--) {
        if(Hc[i][j] > 0) chmax(Hc[i][j], Hc[i+1][j]);
        if(Wc[i][j] > 0) chmax(Wc[i][j], Wc[i][j+1]);
        chmax(ans, Hc[i][j] + Wc[i][j] - 1);
    }
    cout<<ans<<endl;
    return 0;
}