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
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tiii;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> pq(2*N);
    rep(i,N) {
        ll a, b;
        cin >> a >> b;
        pq[2*i] = b;
        pq[2*i+1] = (a-b);
    }
    sort(pq.rbegin(), pq.rend());
    ll ans = 0;
    rep(i,K) ans += pq[i];
    
    cout << ans << endl;
    return 0;
}