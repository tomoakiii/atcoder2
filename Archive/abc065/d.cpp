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
typedef pair<ll, pair<int,int>> pll;
int main(){
    ll N;
    cin >> N;
    vector<pair<ll,int>> X(N), Y(N);
    rep(i,N) {
        cin>>X[i].first>>Y[i].first;
        X[i].second = Y[i].second = i;
    } 
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    dsu UF(N);
    priority_queue<pll,vector<pll>,greater<pll>> que;
    rep(i,N-1) {
        que.push({{X[i+1].first - X[i].first}, {X[i].second, X[i+1].second}});
        que.push({{Y[i+1].first - Y[i].first}, {Y[i].second, Y[i+1].second}});
    }
    ll ans = 0;
    while(!que.empty()) {
        auto [cost, uv] = que.top();
        auto [u,v] = uv;
        que.pop();
        if(UF.same(u,v)) continue;
        UF.merge(u,v);
        ans += cost;
    }
    cout << ans << endl;
    return 0;
}