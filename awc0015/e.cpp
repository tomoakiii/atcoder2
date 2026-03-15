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
    ll N,M,C;
    cin >> N >> M >> C;
    ll ln = sqrt(1e5);
    vector<ll> A(N),B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int j=0;
    ll ans = 0;
    rep(i,N) {
        if(B[j]>A[i]) continue;
        ans+=C;
        j++;
        if(j==M) break;
    }
    cout<<ans<<endl;
    return 0;
}