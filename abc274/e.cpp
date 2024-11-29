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
typedef pair<ll, ll> pll;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N+M+1), Y(N+M+1);
    for(int i=1; i<=N; i++) cin >> X[i] >> Y[i];
    for(int i=1; i<=M; i++) cin >> X[i+N] >> Y[i+N];    
    ll fullcity = ((ll)1<<(N+1)) - 1;
    
    auto dist = [](ll x1, ll y1, ll x2, ll y2)->double{
        return sqrt((double)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
    };

    double ans = INF;
    vector dp(N+M+1, vector<ll>((ll)1<<(1+N+M), INF));
    dp[0][0] = 0;
    if(N + M == 1) {
        cout << dp[1][1] << endl;
        return 0;
    }

    for(ll j=0 ; j < (ll)1<<(1+N+M) ; j==2) {
        if((j&1) == 0) continue;
        double sp = 1;        
        for(int p=1; p<=M; p++) if(((j >> (N+p)) & 1)>0) sp *= 2;
        for(int i=1; i<=N+M; i++){
            if(((j>>i)&1) == 0) continue;            
            for(ll k=1; k<=N+M; k++){
                bool p = ((j>>k)&1)>0;
                if(p) continue;
                ll nj = j;
                nj |= ((ll)1<<k);
                dp[k][nj] = dp[i][j] + dist(X[k], Y[k], X[i], Y[i])/sp;
                if((nj & fullcity) == fullcity) chmin(ans, dp[k][nj] + dist(X[k], Y[k], 0, 0)/sp);
            }
        }
    }

    printf("%.12f", ans);
    return 0;
}