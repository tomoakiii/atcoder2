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
    ll N, A, B;
    cin >> N >> A >> B;
    bool flg = true;
    rep(i, A*N) {
        if(i%A == 0) flg = !flg;
        bool flg2 = true;
        rep(j, B*N) {
            if(j%B == 0) flg2 = !flg2;
            if(flg == flg2) printf(".");
            else printf("#");
        }
        printf("\n");
    }
    return 0;
}