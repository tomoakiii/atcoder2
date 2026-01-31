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
    for(ll a=1; a<=N; a++) {
        for(ll b=1; b<=N; b++) {
            if(a+b<=K-1) {
                if(K-a-b <= N) ans++;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}