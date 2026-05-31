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

void solve(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ok = 1, ng = 1e9 + 1;
    while(ng - ok > 1) {
        ll c = (ng + ok)/2;
        ll cnt = 0;
        rep(i, N) {
            ll a = A[i];
            unordered_map<ll, ll> mp;
            mp[a]++;
            while(true) {
                auto it = mp.end();
                mp--;
                auto [q, v] = *it;
                ll q2 = q/2;
                ll q3 = q - q2;
                if(q2 > 0) mp[q2]+=c;
                if(q3 > 0) mp[q3]+=c;
            }
        }
    }

    return 0;
}

int main(){
    ll T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}