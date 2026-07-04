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
    ll N,M;
    cin >> N >> M;
    vector A(N+1, vector<ll>(M));
    rep(i,N)rep(j,M) cin>>A[i+1][j];
    rep(j,M) rep(i,N){
        A[i+1][j]+=A[i][j];
    }
    ll ans=-INF;
    rep(r1,N) for(int r2=r1+1;r2<=N;r2++){
        vector<ll> C(M);
        rep(j,M) {
            C[j] = A[r2][j] - A[r1][j];
        }
        ll mn=0;
        ll sm=0;
        rep(j,M) {
            sm += C[j];
            chmax(ans, sm-mn);
            chmin(mn, sm);
        }
    }
    cout<<ans<<endl;
    return 0;
}