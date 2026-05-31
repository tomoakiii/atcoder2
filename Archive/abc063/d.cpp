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
    ll N,A,B;
    cin >> N >> A >> B;
    vector<ll> h(N);
    ll D = A-B;
    rep(i,N)cin>>h[i];
    sort(h.rbegin(), h.rend());
    ll ng = 0, ok = 1e9;

    while(ok-ng>1) {
        ll c = (ok+ng)/2;
        ll cnt = 0;
        rep(i,N) {
            ll t = h[i] - c*B;
            if(t <= 0) break;
            cnt += (t+D-1)/D;
        }
        if(cnt > c) ng = c;
        else ok = c;
    }
    cout<<ok<<endl;
    return 0;
}