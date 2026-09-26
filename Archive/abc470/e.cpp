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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,L;
    cin >> N >> L;
    double ave=0;
    rep(i,N){
        ll a; cin>>a; ave+=a;
    }
    ave/=N;

    vector dp(201, vector(201, vector(201, vector<double>(2,0))));
    dp[0][0][0] = 1;

    rep(i,2*N){
        vector dp2(201, vector(201, vector(201, vector<double>(2,0))));
        rep(j,L){
            rep(k,2*N){
                ll rm = 2*N - (2*i);
                double p = 1.0/(double)rm;
                double p2 = 1.0/(double)(rm-1);

                // 1st shot
                if(i>0 && k+2<=2*N) dp2[i-1][j][k+2][0] += dp[i][j][k][0] + p * ();
                if(i>0) dp2[i-1][j][][0] += dp[i][j][][1];



                dp_new[i+1][j+1][1] += dp[i][j][0] + (1-p)*p2;
                dp_new[i+1][j+1][0] += dp[i][j][0] + (1-p)*(1-p2);
            }
        }
    }

    return 0;
}