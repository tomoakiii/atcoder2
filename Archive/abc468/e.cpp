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
typedef modint998244353 mint;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<mint> INV(N+1);
    mint sm = 0;
    for(int i=1;i<=N;i++){
        mint k=i;
        INV[i] = k.inv();
        sm += INV[i];
    }
    vector<mint> INVsm(N+1);
    rep(i,N){
        INVsm[i+1]=INVsm[i]+INV[i+1];
    }
    vector<mint> K(N);
    int id=1;
    rep(i,(N+1)/2){
        K[i]=sm;
        sm += INVsm[N-id]-INVsm[id];
        id++;
    }
    rep(i,N/2){
        K[N-i-1]=K[i];
    }
    mint ans = 0;
    rep(i,N){
        ans += A[i] * K[i];
    }
    cout << ans.val() << endl;
    return 0;
}