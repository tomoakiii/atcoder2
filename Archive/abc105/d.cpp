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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]%=M;
    }
    ll sm = 0;
    unordered_map<ll,ll> mp;
    mp[0]++;
    ll ans = 0;
    rep(i,N) {
        sm += A[i];
        sm %= M;
        ans += mp[sm];
        mp[sm]++;
    }
    cout<<ans<<endl;
    return 0;
}