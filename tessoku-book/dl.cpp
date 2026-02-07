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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N,D; cin>>N>>D;
    priority_queue<ll> que;
    vector X(D+1, vector<ll>{});
    rep(i,N) {
        int x,y; cin>>x>>y;
        X[x].push_back(y);
    }
    ll ans = 0;
    rep(i,D+1) {
        for(auto y: X[i]) que.push(y);
        if(que.empty()) continue;
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}