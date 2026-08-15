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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,D;
    cin >> N >> D;
    map<ll,ll> mp;
    rep(i,N) {
        ll x,c; cin>>x>>c;
        mp[x]=c;
    }
    typedef pair<ll,ll> pll;
    priority_queue<pll,vector<pll>,greater<pll>>que;
    ll ans = INF;
    for(auto [x,c]:mp){
        while(!que.empty()){
            auto [lc,lx] = que.top();
            if(lx + D < x) {
                que.pop();
                continue;
            } else {
                chmin(ans, c+lc);
                break;
            }
        }
        que.push({c,x});
    }
    if(ans==INF) cout<<-1<<endl;
    else cout << ans << endl;
    return 0;
}