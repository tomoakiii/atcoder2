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
    ll ans = INF;
    rep(nn, N+1) {
        ll p = nn;
        ll q = N - p;
        ll sm = 0;
        ll d2[2] = {6,9};
        rep(k,2){
            ll d = d2[k];
            while(d < p) {
                d *= d2[k];
            }
            while(d > 0) {
                sm += p / d;
                p %= d;
                d /= d2[k];
            }
            swap(p, q);
        }
        chmin(ans, sm);
    }

    cout<< ans << endl;
    return 0;
}