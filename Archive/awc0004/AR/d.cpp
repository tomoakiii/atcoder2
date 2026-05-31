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
typedef pair<ll,ll> pll;
int main(){
    ll N,M; cin >> N>>M;
    vector LR(N, vector<int>{});
    rep(i,M) {
        int l,r; cin>>l>>r; l--,r--;
        LR[l].push_back(r);
    }
    priority_queue<pll,vector<pll>,greater<pll>> que;
    rep(i,N) {
        for(auto v: LR[i]) que.push({v,i});
        if(que.empty()) continue;
        auto [rp,lp] = que.top();
        if(lp<=i && i<=rp) que.pop();
    }
    if(que.empty()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}