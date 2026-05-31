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
typedef modint1000000007 mint;

int main(){
    ll N; cin>>N;
    vector<mint> A(N);
    mint sm=0;
    rep(i,N) {
        ll a; cin>>a;
        A[i]=a;
        sm+=a;
    }
    mint ans=0;
    rep(i,N-1){
        sm-=A[i];
         ans+=sm*A[i];
    }
    cout << ans.val()<< endl;
    return 0;
}