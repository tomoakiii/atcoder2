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
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> A(K);
    rep(i,K) cin >> A[i].first >> A[i].second;
    sort(A.begin(),A.end());
    ll sm=0;
    rep(i,N) {
        ll c;
        cin >> c;
        sm += c;
    }
    auto it = upper_bound(A.begin(),A.end(),make_pair(sm,INF)) - A.begin();
    if (it == 0) {
        cout << sm << endl;
    } else {
        auto [x,y] = A[it-1];
        ll disc = sm * y / 100;
        cout << sm - disc << endl;
    }
    return 0;
}