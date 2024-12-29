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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll alxor = 0;
    rep(i,N) {
        cin>>A[i];
        alxor ^= A[i];
    }

    bool flg = (K < N/2);
    if(!flg) K = N - K;
    ll ans = 0;
    auto f = [&](auto f, int cnt, int i, ll t)->void {
        if (cnt == K) {
            if(flg) chmax(ans, t);
            else chmax(ans, alxor^t);
            return;
        }
        if(i < N) {
            f(f, cnt+1, i+1, t^A[i]);
            f(f, cnt, i+1, t);
        }
    };
    
    f(f, 0, 0, 0);
    cout << ans << endl;
    return 0;
}