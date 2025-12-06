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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans = 0;
    rep(l,N) for(int r = l; r<N; r++) {
        ll sm = 0;
        for(int k = l; k<=r; k++) sm += A[k];
        bool flg = true;
        for(int k = l; k<=r; k++) if(sm % A[k] == 0) flg = false;
        if(flg) ans++;
    }
    cout << ans << endl;
    return 0;
}