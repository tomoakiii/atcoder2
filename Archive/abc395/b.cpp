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
    vector G(N, vector<char>(N, '#'));
    for(int i = 1; i <= N/2; i+=2) {
        for(int j = i; j < N-i; j++) {
            G[i][j] = '.';
        }
        for(int j = i; j < N-i; j++) {
            G[N-i-1][j] = '.';
        }
        for(int j = i; j < N-i; j++) {
            G[j][i] = '.';
        }
        for(int j = i; j < N-i; j++) {
            G[j][N-i-1] = '.';
        }
    }
    rep(i,N) {
        rep(j,N) printf("%c", G[i][j]);
        printf("\n");
    }
    return 0;
}