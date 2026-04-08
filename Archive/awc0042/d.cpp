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
    vector<ll> A(N), B(N+1);
    rep(i,N) cin>>A[i];
    rep(i,N) B[i+1]=(B[i]+A[i])%K;
    unordered_map<ll,ll> mp;
    mp[0]++;
    ll ans = 0;
    rep(i,N) {
        if(mp.contains(B[i+1])) ans+=mp[B[i+1]];
        mp[B[i+1]]++;
    }
    cout<<ans<<endl;
    return 0;
}