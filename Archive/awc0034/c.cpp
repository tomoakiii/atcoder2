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
    ll N,K,T,P;
    cin >> N >> K >> T >> P;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> C(N+K+1);
    ll ans=0;
    rep(i,N) {
        ll k = T-A[i]-C[i];
        if(k>0) {
            ans+=k;
            C[i]+=k;
            C[i+K]-=k;
        }
        C[i+1]+=C[i];
    }
    cout<<ans*P<<endl;
    return 0;
}