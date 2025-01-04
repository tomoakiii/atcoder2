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
    ll N, P, Q;
    cin >> N >> P >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    rep(a,N) for(int b=a+1; b<N; b++) for(int c=b+1; c<N; c++) for(int d=c+1; d<N; d++) for(int e=d+1; e<N; e++) {
        ll p = 1;
        p *= A[a]; p %= P;
        p *= A[b]; p %= P;
        p *= A[c]; p %= P;
        p *= A[d]; p %= P;
        p *= A[e]; p %= P;
        if(p%P==Q) ans++;
    }
    cout << ans << endl;
    return 0;
}