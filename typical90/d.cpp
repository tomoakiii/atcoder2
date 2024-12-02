#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int H,W;
    cin >> H >> W;
    vector G(H, vector<int>(W));
    vector<int> Sr(W), Sc(H);
    rep(i,H) rep(j,W) {
        cin>>G[i][j];
        Sr[j] += G[i][j];
        Sc[i] += G[i][j];
    }
    rep(i,H) {
        rep(j,W) {
            printf("%d ", Sr[j] + Sc[i] - G[i][j]);
        }
        printf("\n");
    }
    return 0;
}