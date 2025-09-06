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
    int N;
    cin >> N;
    vector<int> A(N);
    map<int,ll> mp;
    rep(i,N) {
        int a; cin >> a;
        mp[i-a]++;
        A[i] = a;
    }
    ll ans = 0;
    rep(i,N) {
        ans += mp[i + A[i]];
    }
    cout << ans << endl;
    return 0;
}