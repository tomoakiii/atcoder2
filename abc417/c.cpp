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
    vector<ll> B(N);
    rep(i,N) B[i] = (i+1) - A[i];
    map<ll,ll> mp;
    rep(i,N) mp[A[i]+i+1]++;
    ll ans = 0;
    for(auto b:B) ans += mp[b];
    cout << ans << endl;
    return 0;
}