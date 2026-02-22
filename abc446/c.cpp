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

void solve(){
    ll N,D; cin>>N>>D;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    deque<ll> que;
    rep(i,N) {
        rep(k,A[i]) que.push_back(i);
        rep(k,B[i]) que.pop_front();
        while(!que.empty() && que.front() + D <= i) {
            que.pop_front();
        }
    }
    cout << que.size() << endl;
}

int main(){
    ll T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}