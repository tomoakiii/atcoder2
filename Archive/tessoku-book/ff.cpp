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
    vector<string> S(N);
    vector<int> T(N);
    rep(i,N) cin>>S[i]>>T[i];
    vector<string> ans;
    rep(t, 10000) {
        bool flg = true;
        string X = "0000";
        ll tt = t;
        rep(i,4) {
            X[i] = '0' + tt%10;
            tt/=10;
        }
        rep(i,N) {
            int cnt = 0;
            rep(j,4) {
                if(S[i][j] != X[j]) cnt++;
            }
            if(T[i] == 1 && cnt != 0) flg = false;
            else if(T[i] == 2 && cnt != 1) flg = false;
            else if(T[i] == 3 && cnt <= 1) flg = false;
        }
        if(flg) ans.push_back(X);
    }
    if(ans.size() > 1) cout<<"Can't Solve" <<endl;
    else cout << ans[0] << endl;
    return 0;
}