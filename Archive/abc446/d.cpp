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
    unordered_map<ll, ll> mp;
    ll ans = 0;
    rep(i,N) {
        if(mp.contains(A[i]-1)) {
            if(mp.contains(A[i])) chmax(mp[A[i]], mp[A[i]-1] + 1);
            else mp[A[i]] = mp[A[i]-1] + 1;
        } else {
            mp[A[i]] = 1;
        }
    }
    for(auto [m,v]: mp) chmax(ans, v);
    cout << ans << endl;
    return 0;
}