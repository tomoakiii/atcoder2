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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    rep(i,N-1) A[i+1] += A[i];
    map<ll, int> mp;
    // mp[0]++;
    ll ans = 0;
    rep(i,N) {
        if(A[i] == K) ans++;
        ans += mp[A[i]-K];
        mp[A[i]]++;        
    }
    cout << ans << endl;
    return 0;
}