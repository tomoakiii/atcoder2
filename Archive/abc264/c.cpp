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
    ll H1, W1;
    cin >> H1 >> W1;
    vector A(H1, vector<ll>(W1));
    rep(i,H1) rep(j,W1) cin>>A[i][j];
    ll H2, W2;
    cin >> H2 >> W2;
    vector B(H2, vector<ll>(W2));
    rep(i,H2) rep(j,W2) cin>>B[i][j];
    
    rep(i, 1<<H1) rep(j, 1<<W1) {
        vector<int> R{}, C{};
        rep(i2, H1) if ((i>>i2) & 1) R.emplace_back(i2);
        rep(j2, W1) if ((j>>j2) & 1) C.emplace_back(j2);
        if(R.size() != H2 || C.size() != W2) {
            continue;
        }
        bool flg = true;
        rep(i2, H2) rep(j2, W2) if(A[R[i2]][C[j2]] != B[i2][j2]) flg = false;
        if(flg) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}