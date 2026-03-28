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
    ll N,D,S,T;
    cin >> N>>D>>S>>T;
    struct node{
        ll x,y;
    };
    auto dist=[&](node a,node b){
        return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    };
    vector<node> A(N);
    rep(i,N) cin>>A[i].x>>A[i].y;
    vector uv(N,vector<int>{});
    rep(i,N)rep(j,N)if(dist(A[i],A[j])<=D*D)uv[i].push_back(j);
    vector<ll>dp(N,INF);
    S--;T--;
    dp[S]=0;
    queue<int>que;
    que.push(S);
    while(!que.empty()){
        auto q=que.front();
        que.pop();
        for(auto nx:uv[q]){
            if(dp[nx]<=dp[q]+1) continue;
            dp[nx]=dp[q]+1;
            que.push(nx);
        }
    }
    if(dp[T]==INF) cout<<-1<<endl;
    else cout<<dp[T]<<endl;
    return 0;
}