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
    vector A(N+1, vector<ll>(N+1));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            cin >> A[i][j];
        }
    }
    ll ni = A[1][1];

    for(int j=2; j<=N; j++) {
        if (j > ni) ni = A[j][ni];
        else ni = A[ni][j];
    }
    cout << ni << endl;
    return 0;
}