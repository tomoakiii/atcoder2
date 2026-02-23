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
typedef long double ld;
int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N+M), Y(N+M);
    rep(i,N) cin >> X[i] >> Y[i];
    rep(i,M) cin >> X[i+N] >> Y[i+N];
    ll fullcity = (1ll<<N) - 1;
    auto cdist = [&X,&Y](int i, int j)->ld{
        ld x1=X[i], x2=X[j], y1=Y[i], y2=Y[j];
        return sqrtl((ld)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
    };
    vector dist(N+M, vector<ld>(N+M));
    rep(i,N+M) rep(j,N+M) dist[i][j]=cdist(i,j);
    ld ans = 1e16;
    
    if(N+M==1){
        chmin(ans, 2*sqrtl(X[0]*X[0]+Y[0]*Y[0]));
        printf("%.12Lf\n",ans);
        return 0;
    }
    ll P=1ll<<(N+M);
    vector dp(P, vector<ld>(N+M, 1e16));
    vector<ll> speed(P);
    speed[0]=1;
    auto csq = [&](int i)->ld{
        return sqrtl(X[i]*X[i]+Y[i]*Y[i]);
    };
    rep(i,N+M) {
        ll p=1ll<<i;
        dp[p][i] = csq(i);
        if(i>=N) speed[p]=2;
        else speed[p]=1;
    }
    for(ll k=1; k<P; k++) {
        ld sp = speed[k];
        rep(i,N+M){
            if(dp[k][i] > 1e15) continue;
            rep(j, N+M) {
                if(k>>j & 1) continue;
                ll nk = k | (1<<j);
                chmin(dp[nk][j], dp[k][i]+cdist(i,j)/sp);
                if(j>=N) speed[nk]=speed[k]*2;
                else speed[nk]=speed[k];
            }
        }
    }
    rep(k,P) if((k&fullcity)==fullcity) {
        rep(i,N+M)
        chmin(ans, dp[k][i] + csq(i)/speed[k]);
    }
    printf("%.12Lf\n", ans);
    return 0;
}