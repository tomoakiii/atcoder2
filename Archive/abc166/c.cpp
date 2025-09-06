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
    vector<ll> H(N);
    rep(i,N) cin>>H[i];
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int a,b; cin>>a>>b; a--, b--;
        uv[a].push_back(H[b]);
        uv[b].push_back(H[a]);
    }
    int cnt = 0;
    rep(i,N) {
        if(uv[i].empty()){
            cnt++;
            continue;
        }
        sort(uv[i].rbegin(), uv[i].rend());
        if(H[i] > uv[i][0]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}