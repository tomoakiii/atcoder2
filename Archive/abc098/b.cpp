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
    string S;
    cin >> N >> S;
    ll ans = 0;
    for (int i = 1; i <= N - 1; i++) {
        string t = S.substr(0, i);
        string u = S.substr(i, N - i);
        set<char> st;
        for (char c : t) st.insert(c);
        ll cnt = 0;
        for (char c : u) {
            if (st.count(c)) {
                cnt++;
                st.erase(c);
            }
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}