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
    ll H,W,K; cin>>H>>W>>K;
    vector G(H+1,vector<ll>(W+1));
    rep(i,H) {
        string S; cin>>S;
        rep(j,W) {
            if(S[j] == '1') G[i+1][j+1]=1;
        }
    }
    rep(i,H+1)rep(j,W) G[i][j+1]+=G[i][j];
    rep(i,H)rep(j,W+1) G[i+1][j]+=G[i][j];
    /*
    rep(i,H+1){
        rep(j,W+1) cerr<<G[i][j]<<" ";
        cerr<<endl;
    }

    cerr << get(3,2,0,0) << endl;
    cerr << get(3,2,0,1) << endl;
    cerr << get(3,2,0,2) << endl;
    */
    ll ans = 0;
    auto get = [&](int y1, int x1, int y2, int x2)->ll{
        return G[y1][x1] + G[y2][x2] - G[y1][x2] - G[y2][x1];
    };

    rep(i,H+1) rep(nj,W) {
        ll j = nj+1;
        rep(y,i){
            if(get(i,j,y,0) < K) break;
            ll ng = 1+j, ok = 0;
            while(ng-ok > 1){
                ll x = (ok + ng) / 2;
                if(get(i,j,y,x) < K) ng = x;
                else ok = x;
            }
            ll ok2 = j, ng2 = -1;
            while(ok2 - ng2 > 1){
                ll x = (ok2 + ng2) / 2;
                if(get(i,j,y,x) > K) ng2 = x;
                else ok2 = x;
            }
            //cerr << i<< " " << j << " " << y << " " <<  ok << " " << ok2 << endl;
            if(ok >= ok2) ans += (ok - ok2 + 1);
        }
    }
    cout<<ans<<endl;
    return 0;
}