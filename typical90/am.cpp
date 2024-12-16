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
typedef pair<ll,ll> pll;
int main(){
    int N;
    cin >> N;
    vector uv(N, vector<int>{});
    rep(i,N-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uv[a].push_back(b);
        uv[b].push_back(a);
    }
    vector<bool> visit(N, false);
    int ans = 0;
    auto f = [&](auto f, int cur)->int{
        int sm = 0;
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;
            visit[nx] = true;
            sm += f(f, nx);
        }
        ans += sm;
        return 2*sm + 1;
    };
    visit[0] = true;
    f(f, 0);
    cout << ans << endl;
    return 0;
}