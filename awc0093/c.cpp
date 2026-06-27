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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> B(N+1);

    rep(i,N) cin>>A[i];
    rep(i,M){
        ll l,r,d;cin>>l>>r>>d;
        l--,r--;
        B[l]+=d;
        B[r+1]-=d;
    }
    rep(i,N)B[i+1]+=B[i];
    rep(i,N) cout<<A[i]+B[i]<<" \n"[i==N-1];

    return 0;
}