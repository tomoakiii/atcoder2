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
    map<ll, ll> W, B;
    rep(i, M) {
        char c;
        ll x, y;
        cin >> y >> x >> c;
        if(c=='W') {
            if(W.count(x) > 0) chmin(W[x], y);
            else W[x] = y;
        } else chmax(B[x], y);
    }
    ll lasW = INF;
    auto w = W.begin();
    for(auto b: B) {
        if(b.second >= lasW) {
            cout << "No" << endl;
            return 0;
        }
        while(w!=W.end() && w->first <= b.first) {
            if(w->second <= b.second) {
                cout << "No" << endl;
                return 0;
            }
            lasW = w->second;
            w++;
        }
    }
    cout << "Yes" << endl;
    return 0;
}