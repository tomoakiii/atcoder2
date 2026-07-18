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
    ll N, K;
    cin >> N >> K;
    map<ll,ll> mp;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        mp[A[i]]++;
    }
    ll ans=0;
    if(K==0){
        rep(i,N){
            if(mp[A[i]] > 1) ans++;
        }
    }else{
        rep(i,N){
            if(mp.contains(A[i]-K) || mp.contains(A[i]+K)) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}