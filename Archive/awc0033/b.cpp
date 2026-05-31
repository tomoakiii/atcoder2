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
    ll N,K,L,R;
    cin >> N>>K>>L>>R;
    ll ans=0;
    priority_queue<ll,vector<ll>,greater<ll>>que;
    rep(i,N) {
        ll t; cin>>t;
        if(L<=t && t<=R) que.push(0);
        else que.push(min(abs(t-L), abs(t-R)));
    }
    rep(i,K) {
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
    return 0;
}