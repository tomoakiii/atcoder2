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
typedef modint1000000007 mint;
int main() {
    ll N,K; cin>>N>>K;
    vector<ll> A(N);
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        sm += A[i];
    }
    ll ng = 0, ok = 1e9;
    while(ok-ng > 1) {
        ll c = (ok+ng)/2;
        ll cnt = 0;
        rep(i,N) {
            cnt += (A[i]+c-1)/c;
        }
        if(cnt > K) ng = c;
        else ok = c;
    }
    rep(i,N) cout << (A[i]+ok-1)/ok << " ";
    cout<<endl;
    return 0;
}