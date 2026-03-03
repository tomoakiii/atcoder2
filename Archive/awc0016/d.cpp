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
    ll N,K,Q;
    cin >> N >> K >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll sm=0;
    int j=-1;
    vector<int> to(N);
    rep(i,N) {
        while(j<N-1) {
            if(sm>K) break;
            sm+=A[++j];
        }
        to[i]=j+1;
        sm-=A[i];
    }
    vector<ll> B(N+1);
    rep(i,N) B[i+1]=B[i]+to[i];
    while(Q--) {
        int l,r; cin>>l>>r; l--,r--;
        cout<<B[r+1]-B[l]<<endl;
    }
    return 0;
}