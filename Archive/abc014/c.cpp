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
    vector<ll> A(2e6);

    rep(i,N) {
        ll a,b; cin>>a>>b;
        A[a]++;
        A[b+1]--;
    }
    ll ans = A[0];
    rep(i,2e6 - 1){
        A[i+1] += A[i];
        chmax(ans, A[i+1]);
    }
    cout << ans << endl;
    return 0;
}