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
    string S;
    vector<int> pos(26);
    cin >> S;
    rep(i, 26) {
        pos[S[i] - 'A'] = i;
    }
    ll ans = 0;
    rep(i, 25) {
        ans += abs(pos[i+1] - pos[i]);
    }
    
    cout << ans << endl;
    return 0;
}