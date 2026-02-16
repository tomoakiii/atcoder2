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
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

using S = long long;
using F = long long;

const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    ll N,L,K;
    cin>>N>>L>>K;
    deque<pair<ll,ll>> que;
    que.push_back({0,K});
    ll ans = 0;
    auto run = [&](ll a)->bool{
        while(a > 0) {
            if(que.empty()) {
                return false;
            }
            auto &[p, amt] = que.front();
            if(amt >= a) {
                ans += p*a;
                amt -= a;
                return true;
            } else {
                a -= amt;
                ans += p*amt;
                que.pop_front();
            }
        }
        return true;
    };

    ll cur = 0;
    rep(i,N) {
        ll a,c; cin>>a>>c;
        if(!run(a-cur)) {
            cout<<-1<<endl;
            return 0;
        }
        ll pl = a-cur;
        while(!que.empty()) {
            auto &[p, amt] = que.back();
            if(p > c) {
                pl += amt;
                que.pop_back();
            } else {
                break;
            }
        }
        que.push_back({c,pl});
        cur = a;
    }
    if(!run(L-cur)) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}