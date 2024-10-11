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
    ll N; string S;
    cin >> N >> S;
    vector cnt(N, vector<ll> (2));
    cnt[0][S[0]-'0']++;
    ll ans = cnt[0][1];
    for(int i=1; i<N; i++) {
        int x = S[i] - '0';
        cnt[i][1] += cnt[i-1][0];
        if (x == 0) {
            cnt[i][1] += cnt[i-1][1];
        } else {
            cnt[i][0] += cnt[i-1][1];
        }
        cnt[i][x]++;
        ans += cnt[i][1];
    }
    cout << ans << endl;
    return 0;
}