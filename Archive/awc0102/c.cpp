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
    ll N,S,K;
    cin >> N >> S >> K;
    S--;
    vector<ll> C(N);
    rep(i,N) cin>>C[i];
    ll ans=0;
    rep(kkk,2){
        vector<ll> A(N+1);
        rep(i,N) A[i+1]=A[i]+C[i];
        for(ll l = max(0ll,S-K); l<=S; l++) {
            ll d = S-l;
            ll rm = K-d-d;
            if(rm < 0) continue;
            ll r = min(S+rm,N-1);
            r++;
            chmax(ans, A[r]-A[l]);
        }
        reverse(C.begin(),C.end());
        S=N-1-S;
    }
    cout<<ans<<endl;
    return 0;
}