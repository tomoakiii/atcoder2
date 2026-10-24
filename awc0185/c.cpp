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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N+1);
    rep(i,N) cin>>A[i+1];
    rep(i,N) A[i+1]+=A[i];
    map<ll,ll>mp;
    ll ans=0;
    rep(i,N+1){
        ll tgt=A[i]-K;
        if(mp.contains(tgt))ans+=mp[tgt];
        mp[A[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}