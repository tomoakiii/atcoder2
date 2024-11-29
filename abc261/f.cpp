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
    vector<ll> C(N), X(N);
    rep(i,N) {
        cin>>C[i];
        C[i]--;
    }
    rep(i,N) {
        cin>>X[i];
        X[i]--;
    }
    vector cs(N, vector<ll>{});
    rep(i,N) {                
        cs[C[i]].emplace_back(X[i]);
    }    
    
    rep(i, N) {
        sort(cs[i].begin(), cs[i].end());
    }

    vector<int> id(N, 0);
    rep(i, N) {
        int col = C[i];
        X[i] = cs[col][id[col]];        
        id[col]++;
    }


    vector<ll> q(2, 0);
    q[1] = INF;

    ll ans = 0;
    reverse(X.begin(), X.end());
    rep(i,N) {
        int it = upper_bound(q.begin(), q.end(), X[i]-1) - q.begin();
        ans += (ll)it;
        q.emplace_back(X[i]);
    }

    cout << ans << endl;
    return 0;
}