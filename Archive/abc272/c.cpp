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
    vector<ll> O{}, E{};
    rep(i,N) {
        ll a;
        cin>>a;
        if (a % 2 == 1) E.emplace_back(a);
        else O.emplace_back(a);
    }
    sort(E.rbegin(), E.rend());
    sort(O.rbegin(), O.rend());
    ll ans = -1;
    if (E.size() >= 2) {
        chmax(ans, E[0] + E[1]);
    }
    if (O.size() >= 2) {
        chmax(ans, O[0] + O[1]);
    }
    cout << ans << endl;
    return 0;
}