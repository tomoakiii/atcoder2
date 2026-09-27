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
    ll N,S,L;
    cin >> N >> S >> L;
    vector<ll> A(N);
    rep(i,N-1) cin>>A[i+1];
    rep(i,N-1) A[i+1]+=A[i];
    S--;
    ll ans = 0;
    rep(i,N) for(int j=i;j<N;j++){
        if(S<i || S>j)continue;
        ll l = A[S]-A[i];
        ll r = A[j]-A[S];
        if(2*l+r <= L || l+2*r<=L) chmax(ans, j-i+1);
    }
    cout << ans << endl;
    return 0;
}