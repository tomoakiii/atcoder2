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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector ab(N, vector<pair<ll, int>>{});
    rep(i, N) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        vector[a].emplace_back({c, b});
        vector[b].emplace_back({c, a});        
    }

    while(Q--){
        int q;
        cin >> q;
        if (q==1){
            priority_queue<ll, vector<ll>, greater<ll>>
        } else {
            int x, y;
            cin >> x >> y;
            x--, y--;
            vector[x].em
        }
    }
    
    cout << sm << endl;
    return 0;
}