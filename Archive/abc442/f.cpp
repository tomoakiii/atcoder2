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
    vector<string> S(N);
    ll sm = 0;
    rep(i,N) {
        string t; cin>>t;
        S[i] = '.' + t;
    }
    vector<ll> dp(N+1);
    rep(i,N) {
        ll totb = 0;
        for(auto c: S[i]) if(c == '#') totb++;
        ll nw = 0, nb = 0;
        vector<ll> dp_new(N+1);
        multiset<ll> st_new;
        rep(j,N+1) {
            char c = S[i][j];
            if(c == '.') nw++;
            else nb++;
            dp_new[j] = (j+1-nw) + (N-j-(totb-nb)) + dp[j];
        }
        swap(dp, dp_new);
        for(int j=N-1; j>=0; j--) {
            chmin(dp[j], dp[j+1]);
        }
    }
    cout << dp[0] << endl;
    return 0;
}
