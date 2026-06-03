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
    vector<set<int>> UF(H);
    rep(i,H) {
        rep(j,W) UF[i].insert(j);
    }

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
            auto nj = UF[ni].lower_bound(j0);
            if(nj==UF[ni].end()) {
                continue;
            }
            while(nj != UF[ni].end() && *nj <= j1) {
                ans += A[ni][*nj];
                nj = UF[ni].erase(nj);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}