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
    ll H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> BmbH(H), BmbW(W);

    for(int y=0; y<H; y++) {
        for (int x=-1; x<=W; x++) {
            BmbH[y].insert(x);
        }
    }

    for(int y=-1; y<=H; y++) {
        for (int x=0; x<W; x++) {
            BmbW[x].insert(y);
        }
    }

    ll ans = H*W;
    while(Q--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        auto erase = [&](int y, int x)->void{
            if (y<H && y>=0 && x<W && x>=0) {
                BmbH[y].erase(x);
                BmbW[x].erase(y);
                ans--;
            }            
        };
        
        auto nxu = BmbH[a].lower_bound(b);
        int x1 = *nxu, x2 = *prev(nxu);
        erase(a, x1);
        if (x1 == b) continue;
        erase(a, x2);
        auto nyu = BmbW[b].lower_bound(a);
        int y1 = *nyu, y2 = *prev(nyu);
        erase(y1, b);
        erase(y2, b);
    }
    cout << ans << endl;
    return 0;
}