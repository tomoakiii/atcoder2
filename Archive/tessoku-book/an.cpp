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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N; cin>>N;
    vector<ll> C(101);
    rep(i,N) {
        ll a; cin>>a;
        C[a]++;
    }
    ll ans = 0;
    for(auto c:C) {
        if(c >= 3) {
            ans += c * (c-1) * (c-2) / 6;
        }
    }
    cout << ans << endl;
    return 0;
}