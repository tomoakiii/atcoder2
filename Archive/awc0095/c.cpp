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
    typedef modint1000000007 mint;
    vector<bool> ng(N+1);
    vector<mint> dp(N+1);
    rep(i,M) {
        ll b; cin>>b;
        ng[b]=true;
    }
    dp[0]=1;
    rep(i,N){
        rep(j,3){
            int nx=i+j+1;
            if(nx>N)break;
            if(ng[nx])continue;
            dp[nx] += dp[i];
        }
    }
    cout<<dp[N].val()<<endl;
    return 0;
}