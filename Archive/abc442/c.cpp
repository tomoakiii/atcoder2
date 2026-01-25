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
    ll N,M;
    cin >> N >> M;
    vector<ll> R(N);
    rep(i,M) {
        int u,v; cin>>u>>v;
        u--,v--;
        R[u]++;
        R[v]++;
    }
    auto func = [](ll x)->ll{
        if(x <= 2) return 0;
        return x * (x-1) * (x-2) / 6;
    };
    rep(i,N) {
        cout << func(N-1-R[i]) << " ";
    }
    cout << endl;
    return 0;
}
