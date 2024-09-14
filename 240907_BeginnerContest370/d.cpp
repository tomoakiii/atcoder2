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
    vector<ll> R(Q), C(Q);
    rep(i, Q) {
        cin >> R[i] >> C[i];
    }

    struct wall{
        int nxtr[4] = {-1, -1, -1, -1}; //r, l, u, f
        int nxtc[4] = {-1, -1, -1, -1};
        bool bomb;
    };

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    vector walls(H+2, vector<wall>(W+2));
    rep(i, H) {
        rep(j, W) {
            walls[i+1][j+1].bomb = false;
            rep(k,4) {
                walls[i+1][j+1].nxtr[k] = i+1+dy[k];
                walls[i+1][j+1].nxtc[k] = j+1+dx[k];
            }
        }
    }
        
    ll ans = H*W;
    rep(i, Q) {
        vector<int> bi{}, bj{};
        if (!walls[R[i]][C[i]].bomb) {
            bi.push_back(R[i]);
            bj.push_back(C[i]);
        } else {
            ll mind = INF;
            rep(k, 4) {
                int ny = walls[R[i]][C[i]].nxtr[k];
                int nx = walls[R[i]][C[i]].nxtc[k];
                int d = abs(ny-C[i]
            }
        }
        rep(p, bi.size()){
            walls[bi[p]][bj[p]].bomb = true;
            int k = walls[bi[p]+1][bj[p]].nextH;
            while(walls[k][bj[p]].bomb) {
                k = walls[k][bj[p]].nextH;
            }
            walls[bi[p]][bj[p]].nextH = k;

             k = walls[bi[p]-1][bj[p]].prevH;
            while(walls[k][bj[p]].bomb) {
                k = walls[k][bj[p]].prevH;
            }
            walls[bi[p]][bj[p]].prevH = k;


             k = walls[bi[p]][bj[p]+1].nextW;
            while(walls[bi[p]][k].bomb) {
                k = walls[bi[p]][k].nextW;
            }
            walls[bi[p]][bj[p]].nextW = k;

            k = walls[bi[p]][bj[p]-1].prevW;
            while(walls[bi[p]][k].bomb) {
                k = walls[bi[p]][k].prevW;
            }
            walls[bi[p]][bj[p]].prevW = k;

            ans --;         
        }        
    }
    cout << ans << endl;
    return 0;
}