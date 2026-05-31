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
    vector<ll> A(N);
    ll ans = INF;
    rep(i,N) cin>>A[i];
    sort(A.begin(), A.end());
    for(int l = 0; l+K-1<N; l++) {
        int r = l+K-1;
        chmin(ans, A[r]-A[l]);
    }
    cout<<ans<<endl;
    return 0;
}