#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
int main(){
    int H, W;
    cin >> H >> W;
    vector A(H, vector<ll>(W));
    vector B(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin>>A[i][j];
    rep(i, H) rep(j, W) cin>>B[i][j];
    ll ans = 0;
    rep(k, H+W-1) {
        int ny = 0;
        int nx = k;
        while(nx >= W-1) {
            nx--;
            ny++;
        }
        while(ny < H - 1 && nx < W - 1 && nx >= 0) {
            ll d = B[ny][nx] - A[ny][nx];
            ans += abs(d);
            // cout << ny << " " << nx << endl;
            A[ny][nx] += d;
            A[ny+1][nx] += d;
            A[ny][nx+1] += d;
            A[ny+1][nx+1] += d;
            ny += 1;
            nx -= 1;
        }
    }
    rep(i, H) rep(j, W) {
        if(A[i][j] != B[i][j]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
    return 0;
}