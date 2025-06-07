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
    ll st = N, nx;
    ll ans = 0;
    if(N==1) {
        cout<<1<<endl;
        return 0;
    }
    for(ll x = 1; x * x < N; x++) {
        nx = N / (x+1);
        ans += x * (st - nx);
        st = nx;
    }
    for(ll i=1; i<=nx; i++) {
        ans += N / i;
    }
    cout << ans << endl;
    return 0;
}