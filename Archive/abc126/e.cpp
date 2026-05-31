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
    ll N, M;
    cin >> N >> M;
    dsu UF(N);
    rep(i,M) {
        int x, y, z;
        cin>>x>>y>>z;
        x--,y--;
        UF.merge(x,y);
    }
    cout<<UF.groups().size()<<endl;
    return 0;
}