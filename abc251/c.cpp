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
    ll ans;
    ll mx = 0;
    unordered_set<string> st;
    rep(i,N) {
        string s;
        ll t;
        cin >> s >> t;
        if(st.contains(s)) continue;
        st.insert(s);
        if(mx < t) {
            mx = t;
            ans = i+1;
        }
    }
    cout << ans << endl;
    return 0;
}