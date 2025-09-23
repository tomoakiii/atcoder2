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
    ll H,W,K;
    cin >> H >> W >> K;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector G(H+1, vector<int>(W+2));
    rep(i,H) {
        rep(j,W) {
            if(S[i][j] == '1'){
                G[i+1][j+1] = 1;
            }
        }        
    }
    G[0][W+1] = INFi;
    rep(i,H+1) rep(j,W+1) {
        G[i][j+1] += G[i][j];
    }
    rep(i,H) rep(j,W+2) {
        G[i+1][j] += G[i][j];
    }
    ll sprit = 1<<(H-1);
    int ans = INFi;
    rep(k, sprit) {
        vector<int> pos{};
        pos.push_back(0);
        int cnt = 0;
        rep(i, H-1) {
            if(k>>i & 1) {
                pos.push_back(i+1);
                cnt++;
            }
        }
        pos.push_back(H);
        int l = 0;
        bool valid = true;
        while(l < W) {
            int ok = l, ng = W+1;
            while(ng - ok > 1) {
                int middle = (ng + ok) / 2;
                int pics = 0;
                rep(j, pos.size()-1){
                    int nj = pos[j+1];
                    int pj = pos[j];
                    chmax(pics, G[nj][middle] - G[pj][middle] - G[nj][l] + G[pj][l]);
                }
                if(pics <= K) ok = middle;
                else ng = middle;
            }
            if(ok == l) {
                valid = false;
                break;
            }
            if(ok == W) {
                break;
            }
            cnt++;
            l = ok;
        }
        if(valid) {
            chmin(ans, cnt);
        }    
    }
    cout << ans << endl;
    return 0;
}