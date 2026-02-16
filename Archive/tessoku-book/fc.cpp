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
    ll N; cin>>N; N--;
    string ans(10, '4');
    int i = 0;
    while(N) {
        if(N%2) ans[i] = '7';
        N/=2;
        i++;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}