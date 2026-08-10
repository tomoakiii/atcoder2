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
    ll H,W,N;
    cin >> H >> W >> N;
    vector G(H+1, vector<ll>(W+1));

    rep(i,N){
        int a,b,c,d; cin>>a>>b>>c>>d;
        G[a-1][c-1]++;
        G[b][d]++;
        G[a-1][d]--;
        G[b][c-1]--;
    }
    rep(i,H)rep(j,W+1)G[i+1][j]+=G[i][j];
    rep(i,H+1)rep(j,W)G[i][j+1]+=G[i][j];
    rep(i,H)rep(j,W)G[i][j]%=2;
    vector G3(H+1, vector<ll>(W+1));
    rep(i,H)rep(j,W){
        if(G[i][j]) G3[i+1][j+1]++;
    }
    rep(i,H)rep(j,W+1)G3[i+1][j]+=G3[i][j];
    rep(i,H+1)rep(j,W)G3[i][j+1]+=G3[i][j];

    dsu UF(H*W);
    auto toInd=[&](int i,int j){return i*W+j;};
    auto toIJ=[&](int ind){return make_pair(ind/W,ind%W);};
    rep(i,H)rep(j,W){
        if(G[i][j]==0) continue;
        if(i>0 && G[i-1][j]==1) UF.merge(toInd(i,j), toInd(i-1,j));
        if(j>0 && G[i][j-1]==1) UF.merge(toInd(i,j), toInd(i,j-1));
    }
    vector<ll> mR(H*W), mC(H*W);
    vector<ll> lR(H*W,INF), lC(H*W,INF);
    
    rep(i,H)rep(j,W){
        int id=toInd(i,j);
        if(G[i][j]==0) continue;
        int nid = UF.leader(id);
        chmax(mR[nid], i);
        chmax(mC[nid], j);
        chmin(lR[nid], i);
        chmin(lC[nid], j);
    }
    vector<array<ll, 4>> vRC;
    rep(i,H)rep(j,W){
        if(G[i][j]==0) continue;
        int id=toInd(i,j);
        if(UF.leader(id)==id) {
            vRC.push_back({lR[id], mR[id], lC[id], mC[id]});
        }
    }
    int M; cin>>M;
    rep(i,M){
        int p,q,r,s; cin>>p>>q>>r>>s;
        cout<<G3[q][s]+G3[p-1][r-1]-G3[q][r-1]-G3[p-1][s]<<" ";
        int cnt=0;
        for(auto [r1, r2, c1, c2]:vRC){
            if(r1>=p-1 && r2<=q-1 && c1>=r-1 && c2<=s-1) cnt++;
        }
        cout<<cnt<<"\n";    
    }
    return 0;
}