#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
using mint = modint998244353;
int main(){
    int N,A,B,P,Q;
    cin >> N >> A >> B >> P >> Q;
    int Tg = N-A, Ta = N-B;
    vector dpg(Tg+1, vector<mint>(Tg+1)), dpa(Ta+1, vector<mint>(Ta+1));
    dpg[0][0] = 1;
    dpa[0][0] = 1;
    mint invP = 1, invQ = 1;
    invP = invP / P;
    invQ = invQ / Q;

    
    for(int i=1; i<=Tg; i++) {
        for(int j=0; j<Tg; j++) for (int k=1; k<=P; k++) {
            int nk = min(j+k, Tg);
            dpg[i][nk] += dpg[i-1][j] * invP;
        }
    }
    for(int i=1; i<=Ta; i++) {
        for(int j=0; j<Ta; j++) for (int k=1; k<=Q; k++) {
            int nk = min(j+k, Ta);
            dpa[i][nk] += dpa[i-1][j] * invQ;
        }
    }
    mint ans = 0;
    rep(i, Tg+1) {
        rep (j, Ta+1){
            if (i <= j) {
                ans += dpg[i][Tg] * dpa[j][Ta];
            }
        }
    }
    cout << ans.val() << endl;

    return 0;
}