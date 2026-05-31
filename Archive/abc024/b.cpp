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
    ll N,T;
    cin >> N >> T;
    ll M = 2e6;
    vector<ll> time(M);
    rep(i,N){
        ll a;cin>>a;
        time[a]++;
        time[a+T]--;
    }
    ll ans = 0;
    rep(i,M-1) {
        time[i+1] += time[i];
        if(time[i] > 0) ans++;
    }
    cout << ans << endl;

    return 0;
}