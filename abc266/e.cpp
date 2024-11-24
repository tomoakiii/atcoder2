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
    int N;
    cin >> N;
    vector S(N+1, vector<pair<double, double>>(6));
    double os = 1/6;
    double ros = os;
    rep(j,6) S[0][j].second = 1;

    rep(j,6) {
        double ss = 0;
        for(int j2=j+1; j2<=6; j2++) {
            ss += j2;
        }
        ss *= os;
        rep(i,N-1) {
            S[i+1][j].first = S[i][j].first + S[i][j].second * ss;
            S[i+1][j].second = S[i][j].second * os;
        }
        S[N][j].first = S[N-1][j].first;
        rep(j2, 6) {
            S[N][j].first += S[N-1][j].second * os * (j2+1);
        }
    }
    vector<double> P(N+1);
    rep(i,N) {
        int rem = N - i;
        
        rep(j,N) {
            S[rem][]
        }
    }
    return 0;
}