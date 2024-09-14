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
    vector A(N, vector<int>(N)), B(N, vector<int>(N)), AA(N, vector<int>(N));
    rep(i,N) rep(j,N) cin >> A[i][j];
    rep(i,N) rep(j,N) cin >> B[i][j];
    
    rep (k, 4) {
        bool ok = true;
        rep(i,N) rep(j,N){
            if (A[i][j] == 1 && B[i][j] != 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
        vector AA = A;
        rep(i,N) rep(j,N) AA[i][j] = A[N-1-j][i];
        swap(A, AA);
    }
    cout << "No" << endl;
    return 0;
}