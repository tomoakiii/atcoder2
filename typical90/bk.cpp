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
    int H, W;
    cin >> H >> W;
    vector P(H, vector<int>(W, 0));
    rep(i,H) rep(j,W) {
        cin>>P[i][j];
        P[i][j]--;
    }
    vector R(H, vector<int>(8)), C(W, vector<int>(8));
    rep(i,H) rep(j,W) {
        R[i][P[i][j]] = 1;
        C[j][P[i][j]] = 1;
    }
    
    ll ans = 0;
    rep(p, 8) {
        ll r = H, c = W;
        rep(i,H) {
            rep(j,W) {
                if(P[i][j] != p) {
                    r--;
                    break;
                }
            }            
        }
        rep(j,W) {
            rep(i,H) {
                if(P[i][j] != p) {
                    c--;
                    break;
                }
            }            
        }
        chmax(ans, r*c);
    }
    cout << ans << endl;
    return 0;
}