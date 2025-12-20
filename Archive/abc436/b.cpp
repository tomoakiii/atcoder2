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
    vector G(N, vector<ll>(N));
    int r = 0, c = (N-1)/2;
    G[r][c] = 1;
    int k = 1;
    rep(i, N*N-1) {
        int nr = (r+N-1)%N;
        int nc = (c+1)%N;
        if(G[nr][nc] == 0) G[nr][nc] = k+1;
        else {
            nr = (r+1)%N;
            nc = c;
            G[nr][nc] = k+1;
        }
        k++;
        r = nr;
        c = nc;
    }
    for(auto g: G) {
        for(auto a: g) cout<<a<<" ";
        cout<<endl;
    }

    return 0;
}