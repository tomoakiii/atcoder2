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
    ll N,T;
    cin >> N >> T;
    ll st = -1;
    ll ed = -1;
    ll ans = 0;
    bool last = false;
    rep(i,N) {
        ll t; cin>>t;
        if(t > ed) {
            ans += ed - st;
            st = t;
            ed = t + T;
        } else {
            ed = t + T;
        }
    }
    ans += ed - st;
    cout << ans << endl;
    return 0;
}