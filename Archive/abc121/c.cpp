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
    ll N,M;
    cin >> N >> M;
    priority_queue<pll,vector<pll>,greater<pll>> que;
    rep(i,N) {
        pll p;
        cin>>p.first>>p.second;
        que.push(p);
    }
    ll ans = 0;
    while(M > 0) {
        auto [a,b] = que.top();
        que.pop();
        if(b > M) {
            ans += a*M;
            M = 0;
        }
        else {
            ans += a*b;
            M -= b;
        }
    }
    cout<<ans<<endl;
    return 0;
}