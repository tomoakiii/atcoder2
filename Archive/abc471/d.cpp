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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll Q,V;
    cin >> Q >> V;
    priority_queue<pair<ll,ll>> que;
    while(Q--){
        int quer; cin>>quer;
        if(quer == 1){
            ll t, w; cin>>t>>w;
            que.push({w-t, t});
        } else {
            ll tc; cin>>tc;
            if(que.empty()) {
                cout << -1 << endl;
                continue;
            }
            auto [wt,t] = que.top();
            que.pop();
            ll w = wt + t;
            ll td = tc - t;
            cout << min(V, w + td) << endl;
        }
    }
    return 0;
}