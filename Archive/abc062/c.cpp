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

    ll ans = INF;
    rep(kkk,2){
        ll p1 = W/2;
        ll p2 = W - p1;
        vector<ll> pieces(3);
        ll r = H/3;
        ll r2 = (H-r)/2;
        ll r3 = (H-r-r2);
        pieces[0] = r*W;
        pieces[1] = r2*W;
        pieces[2] = r3*W;
        sort(pieces.begin(), pieces.end());
        if(pieces[0] > 0) chmin(ans, pieces[2]-pieces[0]);

        for(ll i=1; i<H; i++) {
            pieces[0] = i * W;
            ll rm = H - i;
            pieces[1] = p1 * rm;
            pieces[2] = p2 * rm;
            sort(pieces.begin(), pieces.end());
            if(pieces[0] > 0) chmin(ans, pieces[2]-pieces[0]);
        }
        swap(H,W);
    }
    cout<<ans<<endl;
    return 0;
}