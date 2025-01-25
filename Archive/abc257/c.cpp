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
    string S;
    cin >> S;    
    vector<ll> Wa{}, Wc{};
    rep(i, N) {
        ll w;
        cin >> w;
        if (S[i] == '1') {
            Wa.emplace_back(w);
        } else {
            Wc.emplace_back(w);
        }
    }

    sort(Wa.begin(), Wa.end());
    sort(Wc.begin(), Wc.end());
    
    ll ans = 0;
    rep(i, Wa.size()) {
        ll sc = 0;
        sc += Wa.size() - i;
        int it = lower_bound(Wc.begin(), Wc.end(), Wa[i]) - Wc.begin();
        sc += it;
        chmax(ans, sc);
    }

    rep(i, Wc.size()) {
        ll sc = 0;
        sc += i+1;
        int it = lower_bound(Wa.begin(), Wa.end(), Wc[i]+1) - Wa.begin();
        sc += Wa.size() - it;
        chmax(ans, sc);
    }

    cout << ans << endl;
    return 0;
}