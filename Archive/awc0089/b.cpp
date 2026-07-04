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
    ll N,D,K,C;
    cin >> N >> D>> K >> C;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        ll b; cin >> b;
        if(b==1) A[i] = max(0ll, A[i]-C);
    }
    sort(A.rbegin(), A.rend());
    ll ans = A[0];
    ll sm = A[0];
    for(int i=1; i<N; i++) {
        sm += (A[i]-K);
        chmax(ans, sm);
    }
    if(ans >= D) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}