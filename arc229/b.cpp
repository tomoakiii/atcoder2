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

void solve(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    rep(i,N-1){
        if(A[i] < A[i+1]){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    ll rm = 0;
    for(int i=N-1;i>0;i--){
        A[i] -= rm;
        ll r = 0;
        while(A[i]){
            A[i] /= 2;
            r++;
        }
        ll d = A[i-1]-A[i];
        ll r = (d+1)/2;
        ans += r;
        A[i-1] -= 2*r;

    }
    cout << ans << endl;
    return 0;
}


int main(){
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}