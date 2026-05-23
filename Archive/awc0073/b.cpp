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
    ll N,K;
    cin >> N >> K;
    priority_queue<ll> que;
    ll sm=0;
    rep(i,N) {
        ll a,b; cin>>a>>b; sm+=a;
        que.push(b-a);
    }
    rep(i,K) {
        auto q=que.top();
        que.pop();
        sm+=q;
    }
    cout<<sm<<endl;
    return 0;
}