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
    ll N, M;
    cin >> N >> M;
    vector<ll> ans;
    auto f=[&](auto f, int i, bool b, ll p, int cnt) {
        if(b) {
            p |= (1<<i);
            cnt++;
        }
        if(cnt == N) {
            ans.emplace_back(p);
            return;
        }
        if(i==M-1) return;

        f(f, i+1, false, p, cnt);
        f(f, i+1, true, p, cnt);
    };

    f(f, 0, false, 0, 0);
    f(f, 0, true, 0, 0);

    reverse(ans.begin(), ans.end());
    for(auto p: ans) {
        rep(j, M) if((p>>j) & 1) cout<<j+1<<" ";
        cout<<endl;
    }
    return 0;
}