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
    ll T;
    cin >> T;
    while(T--){
        ll N,M,K; cin>>N>>M>>K;
        string S; cin>>S;              
        vector uv(N, vector<ll>{});
        rep(i,M) {
            int u,v; cin>>u>>v;
            u--, v--;
            uv[u].emplace_back(v);
        }
        vector<int> dp(N, -1);
        rep(i,N) dp[i] = (S[i] == 'A');
        auto turn = [&]()->void{
            vector<int> dp_new(N, -1);
            rep(i,N) {
                for(auto nx: uv[i]){
                    if(dp_new[i] == -1 && dp[nx] == 1)  dp_new[i] = 0;
                    if(dp[nx] == 0) dp_new[i] = 1;                    
                }
            }
            swap(dp, dp_new);
        };
        rep(i,K) {
            turn();
            turn();
        }
        if(dp[0] == 1) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }

    return 0;
}