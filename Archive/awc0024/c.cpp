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
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector T(H, vector<bool>(W));
    rep(j,W) {
        vector<int> cnt('z'-'a'+1);
        rep(i,H) {
            int c = S[i][j] - 'a';
            cnt[c]++;
        }
        rep(i,H) {
            int c = S[i][j] - 'a';
            if(cnt[c] == 1) {
                T[i][j] = true;
            }
        }
    }
    rep(i,H) {
        vector<int> cnt('z'-'a'+1);
        rep(j,W) {
            int c = S[i][j] - 'a';
            cnt[c]++;
        }
        rep(j,W) {
            int c = S[i][j] - 'a';
            if(cnt[c] == 1 && T[i][j]) {
                cout<<S[i][j];
            }
        }
    }
    cout<<endl;
    return 0;
}