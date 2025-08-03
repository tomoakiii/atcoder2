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
    vector<ll> P(N), A(N), B(N);    
    rep(i,N) cin>>P[i] >> A[i] >> B[i];
    ll M = 2000;
    ll last = P[N-1];    
    vector<ll> sm(N+1);
    rep(i,N) sm[i+1] = B[i] + sm[i];
    vector dp(N+1, vector<ll>(M));
    
    rep(i,M) dp[N][i] = i;    
    for(int i=N-1; i>=0; i--) {
        rep(j, P[i]+1) {   
            int id = j+A[i];
            dp[i][j] = dp[i+1][id];         
        }
        for(int j = P[i]+1; j<M; j++) {
            int id = max((ll)0, j - B[i]);
            dp[i][j] = dp[i+1][id];
        }
    }
    ll Q; cin>>Q;
    while(Q--){
        ll x; cin >> x;
        if(x >= M) {
            auto id = upper_bound(sm.begin(), sm.end(), x-M) - sm.begin();            
            if(id < N) cout<<dp[id][x-sm[id]]<<endl;
            else cout<<x-sm[N]<<endl;
        }else {
            cout<<dp[0][x]<<endl;
        }
    }

    return 0;
}