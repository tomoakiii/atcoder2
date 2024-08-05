#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N, 0);

    rep(i, N) {
        cin >> A[i];
    }
    vector dp(N, vector<vector<mint>>(N, vector<mint>(N+1, 0)));
    rep(i,N) {
        for(int j=i+1; j<N; j++) {
            dp[i][j][2] = 1;
        }
    }

    rep(i,N) rep(j,N) for(int k=2; k<N; k++) {
        int nk=k+1;
        int ni=j;
        ll tgt = A[j]+(A[j]-A[i]);
        for(int x=j+1; x<N; x++){
            if (A[x] == tgt) {
                dp[ni][x][nk] += dp[i][j][k];
            }
        }
    }

    cout << N << " ";
    for(int k=2; k<=N; k++) {
        mint sm = 0;
        rep(i, N) for(int j=i+1; j<N; j++) {
            sm += dp[i][j][k];
        }
        cout << sm.val() << " ";
    }
    cout << endl;
    return 0;
}