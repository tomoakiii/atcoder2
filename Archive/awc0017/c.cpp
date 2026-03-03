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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> C(N);
    rep(i,N) cin>>C[i];
    vector<ll> A(N);
    rep(i,N-1) if(C[i+1]==C[i]) A[i+1]=1;
    rep(i,N-1) A[i+1]+=A[i];
    while(Q--) {
        int l,r; cin>>l>>r;
        l--,r--;
        cout<<A[r]-A[l]<<endl;
    }
    return 0;
}