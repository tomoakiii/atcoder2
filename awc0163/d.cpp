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
typedef modint998244353 mint;
ll L[2001], R[2001];
const ll offs = 60;
ll N,P,Q,M;

void solve(){
    vector dp(P+1, vector(Q+1, vector<mint>(121,0)));
    dp[0][0][offs]=1;
    rep(i,N){
        auto dp2=dp;
        rep(p,P+1)rep(q,Q+1)rep(d,121){
            for(int j=L[i];j<=R[i];j++){
                // Tak
                if(d+j <= 120 && p+1<=P) dp2[p+1][q][d+j]+=dp[p][q][d];
                // Aok
                if(d-j >= 0 && q+1<=Q) dp2[p][q+1][d-j]+=dp[p][q][d];
            }
        }
        swap(dp,dp2);
    }
    cout << dp[P][Q][offs].val() << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> P >> Q >> M;
    rep(i,N)cin>>L[i]>>R[i];
    rep(i,M){
        ll x,a,b; cin>>x>>a>>b;
        x--;
        L[x]=a,R[x]=b;
        solve();
    }
    return 0;
}