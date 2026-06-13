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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H,W;
    cin >> H >> W;
    vector A(H, vector<ll>(W));
    vector ind(H, vector<int>(W));
    rep(i,H){
        rep(j,W) {
            cin>>A[i][j];
            ind[i][j] = j;
        }
    }
    int Q; cin>>Q;
    vector nx(H,vector<int>(W));
    rep(i,H) {
        rep(j,W) nx[i][j]=j;
    }

    auto findnx = [&](auto findnx, int r, int c)->int{
        if(c>=W) return c;
        if(nx[r][c] == c) return c;
        return nx[r][c] = findnx(findnx, r, nx[r][c]);
    };

    while(Q--) {
        ll ans=0;
        int r,c,d; cin>>r>>c>>d;
        r--,c--;
        int sti = max(r-d, 0);
        int edi = min(r+d, H-1);
        for(int ni=sti; ni<=edi; ni++){
            int p=d-abs(ni-r);
            int j0 = max(0,c-p);
            int j1 = min(W-1, c+p);
            int nj = findnx(findnx, ni, j0);
            while(nj <= j1) {
                ans += A[ni][nj];
                A[ni][nj] = 0;
                nx[ni][nj] = findnx(findnx, ni, nj+1);
                nj = nx[ni][nj];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}