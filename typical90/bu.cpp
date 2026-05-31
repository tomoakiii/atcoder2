#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<unsigned int, unsigned int> pll;
typedef modint1000000007 mint;

int main(){
    ll N;
    cin >> N;
    vector<int> c(N);
    rep(i,N) {
        char a;
        cin >> a;
        c[i] = a-'a';
    }
    vector uv(N, vector<ll>{});
    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uv[a].emplace_back(b);
        uv[b].emplace_back(a);
    }

    vector dp(N, vector<mint>(3, 0)); // only a, only b, a&b

    vector<bool> visit(N, false);

    auto func = [&](auto func, int cur)->void{
        visit[cur] = true;
        int me = c[cur];
        int you = (c[cur]==1)?0:1;
        if(uv[cur].size() == 1 && visit[uv[cur][0]]) {
            dp[cur][me] = 1;
            return;
        }
        mint sm = 1;
        mint smb = 1;
        mint dsm = 1;
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;
            func(func, nx);
            sm *= (dp[nx][me] + dp[nx][2]);
            smb *= (dp[nx][me] + dp[nx][you] + 2*dp[nx][2]);
        }
        dp[cur][me] = sm;
        dp[cur][2] = smb - sm;
    };
    mint ans = 0;
    func(func, 0);
    cout << dp[0][2].val() << endl;
    return 0;
}
