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
    ll N,V;
    cin >> N >> V;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans = 0;
    rep(i,N)rep(j,N){
        if(i==j) continue;
        rep(k,N){
            if(k==i || k==j) continue;
            ll sm = A[i]+A[j]+A[k];
            if(i+j+k+3 > V) continue;
            chmax(ans,sm);
        }

    }
    cout << ans << endl;
    return 0;
}