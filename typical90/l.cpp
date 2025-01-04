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
    int H,W;
    cin >> H >> W;
    dsu UF(H*W);
    ll Q;
    cin >> Q;
    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, 1, -1};
    vector<bool> Grid(H*W, false);
    while(Q--) {
        int q;
        cin >> q;
        if(q==1){
            int r, c;
            cin >> r >> c;
            r--, c--;
            int id = r*W + c;
            Grid[id] = true;
            rep(i,4){
                int ny = r + dy[i];
                int nx = c + dx[i];
                if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                int id2 = ny*W + nx;
                if(Grid[id2]) UF.merge(id, id2);
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            int ida = ra*W + ca;
            int idb = rb*W + cb;
            if(UF.same(ida, idb) && Grid[ida] && Grid[idb]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}