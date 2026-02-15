//https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp
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

int main() {
    ll N; cin>>N;
    vector<ll> C(N);
    rep(i,N) cin>>C[i];
    sort(C.begin(),C.end());
    vector<ll> cnt(N+1);
    ll sm = 0;
    rep(i,N) {
        sm += C[i];
        cnt[i+1] = sm;
    }
    int Q; cin>>Q;
    while(Q--) {
        ll x; cin>>x;
        auto it = upper_bound(cnt.begin(), cnt.end(),x) - cnt.begin();
        cout << it-1 << endl;
    }
    return 0;
}