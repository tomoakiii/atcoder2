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
    ll N,K;
    cin >> N >> K;
    priority_queue<pll> que;
    rep(i,N) {
        ll a,b; cin>>a>>b;
        que.push({min(b,a),a});
    }
    ll ans=0;
    ll cnt=0;
    while(cnt<K && !que.empty()){
        auto [v,rem]=que.top();
        que.pop();
        if(v==0) break;
        ll p=rem/v;
        if(cnt+p<=K) {
            ans+=p*v;
            cnt+=p;
            rem %= v;
            que.push({rem,rem});
        } else {
            p=K-cnt;
            ans+=p*v;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}