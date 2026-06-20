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
    ll H,W,K;
    cin >> H>>W>>K;
    vector<string>S(H);
    rep(i,H)cin>>S[i];
    vector<pair<int,int>> V(K+2);
    int ind=2;
    rep(i,H)rep(j,W){
      if(S[i][j]=='@')V[0]={i,j};
      if(S[i][j]=='G')V[1]={i,j};
      if(S[i][j]=='F')V[ind++]={i,j};
    }

    vector dist(K+2,vector<ll>(K+2,INF));
    typedef pair<ll,pair<int,int>>pli;
    int dy[]={1,-1,0,0};
    int dx[]={0,0,1,-1};
    auto func=[&](int p){
      auto [sy,sx] = V[p];
      vector G(H,vector<ll>(W,INF));
      G[sy][sx]=0;
      priority_queue<pli,vector<pli>,greater<pli>>que;
      que.push({0,V[p]});
      while(!que.empty()){
        auto [q,cur]=que.top();
        auto [ty,tx]=cur;
        que.pop();
        if(G[ty][tx]<q)continue;
        rep(k,4){
          auto ny=ty+dy[k];
          auto nx=tx+dx[k];
          if(nx<0||ny<0||ny>=H||nx>=W)continue;
          if(S[ny][nx]=='#')continue;
          if(chmin(G[ny][nx], G[ty][tx]+1)){
            que.push({G[ny][nx], {ny,nx}});
          }
        }
      }
      rep(k,K+2){
        auto [ty,tx]=V[k];
        dist[p][k]=G[ty][tx];
      }
    };
    rep(i,K+2)func(i);
    vector<int>ord(K);
    rep(i,K)ord[i]=i+2;
    ll ans=INF;
    do{
      int s=0;
      ll sm=0;
      rep(i,K){
        int j=ord[i];
        sm+=dist[s][j];
        s=j;
      }
      if(dist[s][1]>=INF)sm=INF;
      else sm+=dist[s][1];
      chmin(ans,sm);
    }while(next_permutation(ord.begin(),ord.end()));
    if(ans>=INF)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}