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
    map<string, int> blue, red;

    ll N;
    cin >> N;
    rep(i,N) {
        string s; cin>>s;
        blue[s]++;
    }
    ll M;
    cin >> M;
    rep(i,M) {
        string s; cin>>s;
        red[s]++;
    }
    int ans = 0;
    for(auto [b,x]: blue) {
        chmax(ans, x - red[b] );
    }
    cout << ans << endl;
    return 0;
}