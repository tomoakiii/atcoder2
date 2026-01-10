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
    ll N,D,X,Y;
    cin >> N >> D >> X >> Y;
    X = abs(X);
    Y = abs(Y);
    if(X%D != 0 || Y%D != 0) {
        cout<<0<<endl;
        return 0;
    }
    ll x = X/D, y=Y/D;
    ll PN = N-(x+y);
    if(x+y>N || PN%2 != 0) {
        cout<<0<<endl;
        return 0;
    }
    PN /= 2;

    ll MAX_N = 1000;
    vector comb(MAX_N+1, vector<double>(MAX_N));
    for (int i = 0; i <= MAX_N; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
        }
    }

    double ans = 0;
    rep(ppp, PN+1) {
        int qqq = PN-ppp;
        double k = comb[N][qqq];
        int cnt = N;
        while(k > 1 && cnt) {
            k /= 4.;
            cnt--;
        }
        k *= comb[N-qqq][ppp];
        while(k > 1 && cnt) {
            k /= 4.;
            cnt--;
        }
        k *= comb[N-ppp-qqq][y+qqq];
        while(cnt) {
            k /= 4.;
            cnt--;
        }
        ans += k;
    }
    printf("%.13f\n", ans);
    return 0;
}