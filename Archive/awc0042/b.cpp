#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll ans=0;
    ll N,S,T; cin>>N>>S>>T;
    priority_queue<ll,vector<ll>,greater<ll>>que;
    rep(i,N){
      ll a; cin>>a;
      que.push(a);
    }
    while(!que.empty() && que.top()<=S) {
      S+=que.top();
      que.pop();
    }
    if(S>=T)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}