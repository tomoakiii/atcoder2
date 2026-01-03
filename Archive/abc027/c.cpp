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
    ll x = 1;
    bool turn = false;
    while(x <= N) {
        x *= 2;
        turn = !turn;
    }

    auto dfs = [&](auto dfs, ll y, bool ta, int d)->void{
        if(y > N) {
            if(d%2 == 0) cout << "Takahashi" << endl;
            else cout << "Aoki" << endl;
            return;
        }
        if(ta) {
            dfs(dfs, 2*y+1, !ta, d+1);
        } else {
            dfs(dfs, 2*y, !ta, d+1);
        }
    };
    dfs(dfs, 1, turn, 0);

    return 0;
}