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
    vector<ll> cnt(N);
    for(ll i=1; i<N; i++){
        for(ll j=1; j*j<=i; j++) {
            if (i%j == 0) {
                if (j*j == i) cnt[i]+=1;
                else cnt[i]+=2;
            }
        }
    }
    ll ans = 0;
    for(ll i=1; i<N; i++){
        ans += cnt[i] * cnt[N-i];
    }
    cout << ans << endl;
    return 0;
}