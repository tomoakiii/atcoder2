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


struct V {
  ll x, y; int i;
  ll r;
  V(ll x=0, ll y=0, int i=-1): x(x), y(y), i(i) {
    r = sqrtl(x*x + y*y);
  }
  ll cross(const V& a) const { return x*a.y - y*a.x;}
  bool up() const { return y > 0 || (y == 0 && x > 0);}
  bool operator<(const V& a) const {
    if (up() != a.up()) return up();
    return cross(a) > 0;
  }
};

int main(){
    ll N;
    cin >> N;
    ll ns = sqrtl(2e7);
    vector XY(ns+1, vector<pair<pair<ll,ll>, ll>>{});
    rep(i,N) {
        ll x,y; cin>>x>>y;
        ll p = x/ns;
        XY[p].push_back({{y,x}, i});
    }
    deque<int> ans;
    rep(i,ns+1) {
        if(i%2==0) sort(XY[i].begin(), XY[i].end());
        else sort(XY[i].rbegin(), XY[i].rend());;
        for(auto [pxy, j]: XY[i]) {
            ans.push_back(j+1);
        }
    }
    while(ans.front() != 1) {
        ans.push_back(ans.front());
        ans.pop_front();
    }
    for(auto a:ans) {
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}