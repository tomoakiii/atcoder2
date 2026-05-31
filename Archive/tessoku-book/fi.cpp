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
typedef long double ld;
typedef pair<ld,int> pl;
int main() {
    ll N,K; cin>>N>>K;
    vector<ld> A(N);
    rep(i,N) {
        cin>>A[i];
    }
    ld ok = 0, ng = 1e9;
    vector<ll> ans(N);
    while(ng - ok > 0.000001) {
        ld c = (ok+ng)/2;
        ll cnt = 0;
        rep(i,N) {
            cnt += floor(A[i]/c);
        }
        if(cnt < K) ng = c;
        else ok = c;
    }
    rep(i,N) {
        cout << floor(A[i]/ok) << " ";
    }
    cout<<endl;
    return 0;
}