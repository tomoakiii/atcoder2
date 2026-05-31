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
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    if(K==0) {
        cout<<N*N<<endl;
        return 0;
    }
    for(ll b = K+1; b <= N; b++) {
        ll p = N/b;
        ans += p * (b - K);
        ll r = N%b;
        if(r >= K) ans += r-K+1;
    }
    cout << ans << endl;
    return 0;
}