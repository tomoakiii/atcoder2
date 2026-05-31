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
    ll N,W,K;
    cin >> N >> W >> K;
    vector<ll> A(N+1);
    while(K--) {
        int l; cin>>l; l--;
        A[l]+=1;
        A[l+W]-=1;
    }
    rep(i,N) A[i+1]+=A[i];
    rep(i,N) cout<<A[i]<<" \n"[i==N-1];
    return 0;
}