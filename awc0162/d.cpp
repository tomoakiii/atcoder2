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
    ll H,W,R,C;
    cin >> H >> W >> R >> C;
    R--,C--;
    vector dp(H, vector<ll>(W,INF));
    dp[R][C]=0;
    ll M='z'-'a'+1;
    vector<vector<pair<int,int>>> pos(M);
    rep(i,H){
        string S;cin>>S;
        rep(i,W){
            pos[S[j]-'a'].push_back({i,j});
        } 
    }
    ll N; string S;
    cin>>N>>S;
    rep(i,N){
        typedef pair<ll, pair<int,int>> pp;
        priority_queue<pp,vector<pp>,greater<pp>> que;
        rep(i,H)rep(j,W)if(dp[i][j]<INF)que.push({dp[i][j],{i,j}});
        vector dp2(H, vector<ll>(W,INF));
        
    }
    return 0;
}