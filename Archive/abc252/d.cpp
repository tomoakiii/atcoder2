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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans = 0;
    map<ll, ll> mp;

    auto C = [&](ll a) -> ll {
        if(a<2) return 0;
        return a * (a-1) / 2;
    };
    ll ng = 0;
    for(ll i=0; i<N; i++) {
        ll w = mp[A[i]] * (i - mp[A[i]]);
        if(i>=2) ans += C(i) - ng - w;
        ng -= C(mp[A[i]]);
        mp[A[i]]++;
        ng += C(mp[A[i]]);
    }
    cout << ans << endl;
    return 0;
}