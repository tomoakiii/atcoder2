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
    ll N,M;
    cin >> N >> M;
    vector<ll>V(N);
    rep(i,N) cin>>V[i];
    sort(V.rbegin(),V.rend());
    vector<ll> D(M),T(M);
    vector<pair<double,pair<ll,ll>>> DT(M);
    rep(i,M){
        cin>>D[i]>>T[i];
        DT[i].first = (double)D[i]/(double)T[i];
        DT[i].second = {D[i],T[i]};
    }
    sort(DT.begin(),DT.end());
    ll ans=0;
    for(auto v:V) {
        int ok=-1, ng=DT.size();
        while(ng-ok>1) {
            int c=(ok+ng)/2;
            auto [sr,dt]=DT[c];
            auto [d,t]=dt;
            if(v*t>=d)ok=c;
            else ng=c;
        }
        if(ok>=0) {
            ans++;
            while(DT.size()>ok) {
                DT.pop_back();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}