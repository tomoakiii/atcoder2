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
ll op(ll a, ll b) {return min(a,b);}
ll e() {return INF;}
int main(){
    ll N;
    cin >> N;
    vector<ll> H(N);
    rep(i,N) cin>>H[i];
    segtree<ll,op,e> ST(H);
    deque<pair<ll,int>> dq;
    dq.push_back({INF,-1});
    ll ans=0;
    rep(i,N){
      ll a=H[i];
      while(dq.back().first < a) {
        ans+=ST.prod(dq.back().second, i+1);
        dq.pop_back();
      }
      dq.push_back({a,i});
    }
    cout<<ans<<endl;
    return 0;
}