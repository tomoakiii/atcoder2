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
    ll N,M,D;
    cin >> N >> M >> D;
    vector<int> ORD(N);
    rep(i,N) ORD[i] = i;
    auto ST = ORD;
    rep(i,M) {
        int a; cin>>a; swap(ORD[a], ORD[a-1]);
    }
    const ll SZ = 100;
    vector dist(SZ+1, vector<int>(N));
    rep(i,N) {
        dist[0][i] = i;
        dist[1][i] = ORD[i];
    }
    for(int k=2; k<=SZ; k++) {
        rep(i,N) {
            int nx = dist[k-1][i];
            dist[k][i] = dist[k-1][nx];
        }
    }

    int cnt = 0;
    while(D) {
        cnt++;
        if(D%2) {
            vector<int> ST2(N);
            rep(i,N) ST2[i] = dist[cnt][ST[i]];
            swap(ST, ST2);
        }
        D/=2;
    }
    vector<int> ans(N);
    rep(i,N) {
        ans[ST[i]] = i;
    }
    rep(i,N) {
        cout << ans[i]+1 << endl;
    }
    return 0;
}