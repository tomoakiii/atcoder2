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
    vector<ll> T(N);
    ll sm = 0;
    rep(i,N) {
        cin>>T[i];
        sm += T[i];
    }
    ll M; cin>>M;
    rep(i,M) {
        ll p,x; cin>>p>>x;
        p--;
        cout << sm - T[p] + x << endl;
    }

    return 0;
}