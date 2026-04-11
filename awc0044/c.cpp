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
    vector<ll> A(N+1);
    rep(i,M) {
        int l,r; cin>>l>>r; l--,r--;
        A[l]++;
        A[r+1]--;
    }
    rep(i,N) A[i+1]+=A[i];
    rep(i,N) cout<<A[i]<<" \n"[i==N-1];
    return 0;
}