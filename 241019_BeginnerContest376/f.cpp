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
    int N, Q;
    cin >> N >> Q; 
    vector dp(Q+1, vector<ll>(N, INF));
    bool lastL = true;
    dp[0][1] = 0;
    int curLH = 0, curRH = 1, lastnx = 0;
    char c;
    int nx;
    rep(k, Q){
        cin >> c >> nx;
        nx--;
        rep (i, N) {
            if (lastL) {
                curLH = lastnx;
                curRH = i;
            } else {
                curLH = i;
                curRH = lastnx;
            }
            if (dp[k][i] >= INF) continue;
            ll ofs, ofsR;
            int mH = 0, sH;
            if(c=='L') {
                ofs = (N - curLH)%N;
                ofsR = (N - ofs)%N;
                sH = (curRH + ofs)%N;
            } else {
                ofs = (N - curRH)%N;
                ofsR = (N - ofs)%N;
                sH = (curLH + ofs)%N;
            }
            ll nnx = (nx + ofs) % N;
            ll cnt=0;
            if (sH <= nnx) {
                cnt += (nnx - sH + 1);
                cnt += nnx; 
                chmin(dp[k+1][(nnx + 1 + ofsR)%N], dp[k][i]+cnt);
            }
            if (sH > nnx) {
                cnt = nnx;
                chmin(dp[k+1][(sH+ofsR)%N], dp[k][i]+cnt);
            }
            cnt = 0;
            if (sH >= nnx) {
                cnt += (sH - nnx + 1);
                cnt += (N-nnx);
                chmin(dp[k+1][(nnx + (N-1) + ofsR)%N], dp[k][i]+cnt);
            }
            if (sH < nnx) {
                cnt = (N-nnx);
                chmin(dp[k+1][(sH+ofsR)%N], dp[k][i]+cnt);
            }            
        }
        lastnx = nx;
        lastL = (c=='L');
    }

    ll ans = INF;
    rep(i,N) chmin(ans, dp[Q][i]);
    cout << ans << endl;
    
    return 0;
}