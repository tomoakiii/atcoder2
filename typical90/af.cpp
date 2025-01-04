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
    vector A(N, vector<ll>(N));
    rep(i,N) rep(j,N) cin>>A[i][j];
    ll M;
    cin >> M;

    vector uv(N, vector<bool>(N));
    rep(i,M) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        uv[x][y] = true;
        uv[y][x] = true;
    }
    vector<int> ord(N);
    rep(i,N) ord[i] = i;
    ll ans = INF;
    do{
        ll t = 0;
        bool f = true;
        rep(i,N-1) {
            if(uv[ord[i]][ord[i+1]]) {
                f = false;
                break;
            }
        }
        rep(i,N) {
            t += A[ord[i]][i];
        }
        if(f) {
            chmin(ans, t);
        }
    }while(next_permutation(ord.begin(), ord.end()));
    
    if(ans == INF) cout<<-1<<endl;
    else cout << ans << endl;
    return 0;
}