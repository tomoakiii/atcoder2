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
    vector<pair<ll, pair<ll,ll>>> v;
    rep(i,N) {
        ll w,d; cin>>w>>d;
        v.push_back({w+d, {w,d}});
    }
    sort(v.begin(),v.end());
    priority_queue<ll> que;
    ll sm = 0;
    for(auto [x, wd]:v) {
        auto [w,d] = wd;
        que.push(w);
        sm+=w;
        while(sm > x) {
            sm -= que.top();
            que.pop();
        }
    }
    cout << que.size() << endl;
    return 0;
}