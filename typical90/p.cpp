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
typedef pair<ll, int> pli;
int main(){
    ll N;
    vector<ll> ABC(3);
    cin >> N >> ABC[0] >> ABC[1] >> ABC[2];
    sort(ABC.rbegin(), ABC.rend());
    ll sc = N / ABC[0];
    ll ans = INF;
    for(ll c=sc; c>=0; c--) {
        ll sb = (N-c*ABC[0])/ABC[1];
        for(ll b=sb; b>=0; b--) {
            if((N - ABC[0]*c - ABC[1]*b)%ABC[2] == 0) {
                ll a = (N - ABC[0]*c - ABC[1]*b)/ABC[2];
                chmin(ans, a+b+c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}