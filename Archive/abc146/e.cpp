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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
    }
    vector<ll> B(N+1);
    ll ans = 0;

    rep(i,N) {
        B[i+1] = B[i] + A[i];
        B[i+1] %= K;
    }
    unordered_map<ll,ll> mp;
    rep(i,N+1) {
        if(i >= K) {
            mp[B[i-K]]--;
        }
        B[i] += N*K;
        B[i] -= i;
        B[i] %= K;
        if(mp.contains(B[i])) ans += mp[B[i]];
        mp[B[i]]++;
    }

    cout << ans << endl;
    return 0;
}