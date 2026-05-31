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
    ll N,K,M;
    cin >> N >> K >> M;
    ll sm = 0;
    rep(i,N-1) {
        ll a; cin>>a;
        sm += a;
    }
    if(M*N - sm > K) cout << -1 << endl;
    else cout << max(0ll, M*N - sm) << endl;

    return 0;
}