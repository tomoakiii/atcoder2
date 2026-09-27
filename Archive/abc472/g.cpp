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
    ll H,W;cin>>H>>W;
    vector<string> S(H);
    rep(i,N) cin>>X[i]>>Y[i];
    fenwick_tree<ll> FT(2*N),FTx(2*N),FTy(2*N);
    auto crs = [&](int a, int b)->ll{
        a = a%N; b = b%N;
        return X[a]*Y[b] - X[b]*Y[a];
    };
    rep(i,2*N){
        int ni = (i+1)%N;
        int pi = (i)%N;
        ll c= crs(i,ni);
        FT.add(i, c);
        FTx.add(i, (X[pi]+X[ni])*c);
        FTy.add(i, (Y[pi]+Y[ni])*c);
    }

    while(Q--){
        int u,v; cin>>u>>v; u--,v--;
        if(v<u) v+=N;
        ll sm = FT.sum(u,v);
        ll c = crs(v,u);
        sm += c;
        double A = (double)sm/2;

        ll smx = FTx.sum(u,v);
        smx += (X[u%N]+X[v%N])*c;
        double x = (double)smx / (6*A);

        ll smy = FTy.sum(u,v);
        smy += (Y[u%N]+Y[v%N])*c;
        double y = (double)smy / (6*A);

        printf("%.20f %.20f\n", x, y);
    }
    return 0;
}