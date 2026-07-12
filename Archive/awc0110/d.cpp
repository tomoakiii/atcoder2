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
    ll N,K;
    cin >> N >> K;
    priority_queue<pair<ll,ll>> XN,XP;
    rep(i,N) {
        ll x,d; cin>>x>>d;
        if(x>0) XP.push({x,d});
        else XN.push({-x,d});
    }
    ll ans = 0;
    rep(kkkk,2){
        while(!XP.empty()){
            ll rm = K;
            {
                auto [x,d] = XP.top();
                ll p = d/K;
                ans += 2*x*p;
                XP.pop();
                if(d%K>0) XP.push({x,d%K});
                if(XP.empty()) break;
            }
            auto [x,d] = XP.top();
            ans += 2*x;
            while(!XP.empty() && rm>0){
                auto [x,d] = XP.top();
                if(d<=rm) {
                    XP.pop();
                    rm-=d;
                } else {
                    XP.pop();
                    XP.push({x,d-rm});
                    rm = 0;
                    break;
                }
            }
        }
        swap(XP,XN);
    }
    cout<<ans<<endl;
    return 0;
}