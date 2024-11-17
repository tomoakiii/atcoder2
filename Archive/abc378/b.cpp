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
    vector<pair<ll, int>> qr(N);

    rep(i,N)  {
        ll q; int r;
        cin >> q >> r;
        qr[i] = {q, r};
    }
    ll Q;
    cin >> Q;
    while(Q--) {
        int t; ll d;
        cin >> t >> d;
        t--;        
        ll r = (d%qr[t].first);
        if (r <= qr[t].second) {
            cout << (d + qr[t].second - r) << endl;
        } else {
            cout << (d + qr[t].first + qr[t].second - r) << endl;
        }
        

    }
    return 0;
}