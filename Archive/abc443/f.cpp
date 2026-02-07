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
    vector visit(10, vector<pair<int,ll>>(N, {-1,-1}));
    queue<pair<int, ll>> que;
    auto push = [&](int d, ll x)->ll{
        for(ll i = d; i <= 9; i++) {
            if(i < 1) continue;
            ll y = (x * 10 + i)%N;
            if(visit[i][y].second != -1) continue;
            visit[i][y] = {d,x};
            que.push({i, y});
            if(y == 0) {
                return i;
            }
        }
        return -1;
    };
    ll j = push(-1, 0);
    if(j != -1)  {
        cout << j << endl;
        return 0;
    }
    while(!que.empty()) {
        auto [i,q] = que.front();
        que.pop();
        ll j = push(i,q);
        if(j != -1) {
            string ans = "";
            ll y = (q * 10 + j) % N;
            while(j != -1) {
                ans.push_back(j+'0');
                auto [i,x] = visit[j][y];
                j = i; y = x;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}