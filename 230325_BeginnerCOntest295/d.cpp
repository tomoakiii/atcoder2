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
    string S;
    cin >> S;
    map<ll, ll> mp;
    mp[0] = 1;
    ll p=0;
    rep(i, S.size()) {
        ll k = 1ll<<(S[i]-'0');
        if ((p & k) > 0) p -= k;
        else p += k;
        mp[p]++;
    }
    ll ans = 0;
    for(auto m: mp) {
        ans += (m.second) * (m.second-1) / 2;
    }
    cout << ans << endl;
    return 0;
}