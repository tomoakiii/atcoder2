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
    vector S(H, vector<char>(W));
    int a;
    rep(i, H) {
        rep(j, W){
            cin >> a;
            if (a==0) S[i][j] = '.';
            else S[i][j] = 'A' + a - 1;
        }
    }
    rep(i, H) {
        rep(j, W){
            cout << S[i][j];
        }
        cout << endl;
    }
    return 0;
}