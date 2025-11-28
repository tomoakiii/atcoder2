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
    vector<ll> V(N),C(N);
    rep(i,N) cin>>V[i];
    rep(i,N) cin>>C[i];    
    priority_queue<ll> que;
    rep(i,N) que.push(V[i]-C[i]);
    ll ans = 0;
    while(!que.empty()) {
        auto q = que.top();
        que.pop();
        if(q<0) {
            cout<<ans<<endl;
            return 0;
        }
        ans += q;
    }
    cout<<ans<<endl;
    return 0;
}