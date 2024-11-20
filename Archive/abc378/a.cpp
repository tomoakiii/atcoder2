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
    ll N=4;
    vector<ll> A(N);
    
    rep(i, N) {
        int a;
        cin >> a;
        a--;
        A[a]++;
    }

    ll ans = 0;
    rep(i, N) {
        if(A[i] == 2 || A[i] == 3) ans++;
        else if (A[i] == 4) ans += 2;
    }
    
    cout << ans << endl;
    return 0;
}