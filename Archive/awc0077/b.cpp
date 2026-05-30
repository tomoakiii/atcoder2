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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    priority_queue<ll>que;
    rep(i,N){
        ll sm=0;
        rep(j,K){
            if(i+j>=N)break;
            sm+=A[i+j];
            que.push(sm);
        }
    }
    ll ans=0;
    while(M--){
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
    return 0;
}