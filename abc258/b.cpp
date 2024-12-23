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
    ll m = 0;
    vector A(N, vector<ll>(N));
    rep(i,N) {
        string s;
        cin >> s;
        rep(j,N) {
            A[i][j] = s[j] - '0';
            chmax(m, A[i][j]);
        }  
    }
    int dy[] = {0, 0, 1, 1, 1, -1, -1, -1};
    int dx[] = {1, -1, 1, 0, -1, 1, 0, -1};
    ll ans = 0;
    auto f=[&](auto f, int i, int j, int y, int x, int d)->ll{
        if(d == 0) return A[i][j];
        else  {
            ll p = 1;
            rep(x, d) p *= 10;
            int ny = i+y;
            int nx = j+x;
            ny += N; nx += N;
            ny %= N; nx %= N;
            return (p*A[i][j] + f(f, ny, nx, y, x, d-1));
        }
    };
    rep(i,N) rep(j,N) rep(k, 8) {
        ll p = f(f, i, j, dy[k], dx[k], N-1);
        chmax(ans, p);
    }
    cout << ans << endl;
    return 0;
}