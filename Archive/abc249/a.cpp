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
    int t[2], d[2], r[2];
    rep(i,2) cin>>t[i]>>d[i]>>r[i];
    int x;
    cin >> x;
    int dist[2];
    rep(i,2) {
        dist[i] = x / (t[i]+r[i]) * t[i] * d[i];
        int rx = x % (t[i]+r[i]);
        dist[i] += min(t[i], rx) * d[i];
    }
    if(dist[0] == dist[1]) cout << "Draw" << endl;
    else if(dist[0] > dist[1]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}