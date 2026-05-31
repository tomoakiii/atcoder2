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

ll cntd(ll x) {
    ll cnt = 0;
    for(ll i = 1; i<=x; i++) {
        if(x%i == 0) cnt++;
    }
    return cnt;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A;
    int i = 1;
    ll ans = 0;
    while(i <= N) {
        if(cntd(i) == 8) ans++;
        i+=2;
    }
    cout<<ans<<endl;
    return 0;
}