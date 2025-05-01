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
    int N;
    cin>>N;
    vector<ll> A(N),B(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];
    ll ans=0, ans2=0;
    rep(i,N)rep(j,N){
        if(A[i]==B[j]){
            if(i==j) ans++;
            else ans2++;
        }
    }
    cout << ans << endl << ans2 << endl;
    return 0;
}