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
typedef pair<ll,ll> pll;

int main(){
    ll N;
    cin >> N;
    deque<pll> P;
    P.push_back({-INF, 0});
    ll last = -1;
    ll cnt = 0;
    rep(i,N) {
        ll a; cin>>a;
        if(a != last) {
            last = a;
            cnt = 0;
        } else {
            cnt++;
        }
        if(cnt == 3) {
            rep(k,3) P.pop_back();
            last = P.back().first;
            cnt = P.back().second;
        } else {
            P.push_back({last, cnt});
        }
    }
    cout << P.size()-1 << endl;
    return 0;
}