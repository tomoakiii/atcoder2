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
    ll N;
    cin >> N;
    vector A(N, vector<char>(N));
    rep(i,N) rep(j,N) cin>>A[i][j];
    bool flg = true;
    rep(i,N) rep(j,N) {
        if(i==j) continue;
        if(A[i][j] == 'W' && A[j][i] != 'L') flg = false;
        if(A[i][j] == 'L' && A[j][i] != 'W') flg = false;
        if(A[i][j] == 'D' && A[j][i] != 'D') flg = false;
    }
    if(flg) cout << "correct" << endl;
    else cout << "incorrect" << endl;
    return 0;
}