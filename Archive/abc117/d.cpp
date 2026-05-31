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
    ll N,K;    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    const int M = 60;
    vector<ll> sm(M);
    rep(i,N) {
        ll x = A[i];
        ll k=0;
        while(x) {
            sm[k++] += (x%2==1)?1:0;
            x/=2;
        }
    }
    ll X = 0;
    for(ll k=M-1; k>=0; k--) {
        ll X2 = X + (1ll<<k);
        if(2*sm[k] < N) {
            if(X2 <= K) X = X2;
        }
    }

    ll ans = 0;
    rep(i,N) ans += X ^ A[i];
    cout<<ans<<endl;
    return 0;
}