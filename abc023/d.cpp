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
    ll mn = INF;
    ll l = 0, r = 2e9;
    vector<ll> T(N);
    rep(i,N) {
        ll h, s; cin>>h>>s;
        T[i] = h + (N-1)*s;
    }
    while(r - l > 1) {
        ll c = (l+r) / 2;
        bool flg = true;
        rep(i, N) {
            if(T[i] > c) {
                flg = false;
                break;
            }
        }
        if(flg) r = c;
        else l = c;
    }
    cout << l << endl;
    return 0;
}