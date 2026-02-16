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
    set<ll> st;
    for(ll x=1; x*x<=N; x++) {
        if(N%x==0) {
            st.insert(x);
            st.insert(N/x);
        }
    }
    for(auto s:st) cout<<s<<endl;
    return 0;
}