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

    ll mnx = INF, mxx = 0, mny = INF, mxy = 0;
    rep(i,H) rep(j,W) {
        if(S[i][j] == '#') {
            chmin(mnx, j);
            chmax(mxx, j);
            chmin(mny, i);
            chmax(mxy, i);
        }
    }
    rep(i,H) rep(j,W) {
        if(S[i][j] == '.') {
            if(j >= mnx && j <= mxx && i >= mny && i <= mxy) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}