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
    int N;
    cin >> N;
    const int M = 1001;
    vector Grid(M, vector<int>(M));
    rep(i,N) {
        int lx1, ly1, lx2, ly2;
        cin >> lx1 >> ly1 >> lx2 >> ly2;
        Grid[ly1][lx1]++;
        Grid[ly1][lx2]--;
        Grid[ly2][lx2]++;
        Grid[ly2][lx1]--;
    }
    rep(i,M) rep(j,M-1) Grid[i][j+1] += Grid[i][j];
    rep(i,M-1) rep(j,M) Grid[i+1][j] += Grid[i][j];
    vector<int> ans(N+1);
    rep(i,M) rep(j,M) {
        ans[Grid[i][j]]++;
    }
    rep(i,N) cout<<ans[i+1]<<endl;
    return 0;
}