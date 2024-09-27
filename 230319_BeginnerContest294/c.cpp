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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, bool>> AB(N+M);
    rep(i,N) {
        ll a;
        cin >> a;
        AB[i] = {a, true};
    }    
    rep(i,M) {ll a;
        cin >> a;
        AB[i+N] = {a, false};
    }   
    sort(AB.begin(), AB.end());
    rep(i, N+M) {
        if (AB[i].second) cout << i + 1 << " ";
    }
    cout << endl;
    rep(i, N+M) {
        if (!AB[i].second) cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}