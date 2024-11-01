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
    ll H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<int> cnt(N+1, 0);
    vector A(H, vector<int>(W));
    ll ans = 0;
    rep(y,H) rep(x,W) {
        cin>>A[y][x];
        cnt[A[y][x]]++;
        if(cnt[A[y][x]] == 1) ans++;
    }

    rep(y2, H-h+1) {
        rep(x2,W-w+1) {
            if(x2==0){
                rep(y,h) rep(x,w) {
                    cnt[A[y2+y][x2+x]]--;
                    if(cnt[A[y2+y][x2+x]] == 0) ans--;
                }
            } else {
                rep(y, h) {
                    cnt[A[y2+y][x2-1]]++;
                    if(cnt[A[y2+y][x2-1]] == 1) ans++;
                }
            
                rep(y, h) {
                    cnt[A[y2+y][x2+w-1]]--;
                    if(cnt[A[y2+y][x2+w-1]] == 0) ans--;
                }
            }
            cout << ans << " ";            
        }
        cout << endl;
        rep(y,h) rep(x,w) {
            cnt[A[y2+y][W-w+x]]++;
            if(cnt[A[y2+y][W-w+x]] == 1) ans++;
        }        
    }

    return 0;
}