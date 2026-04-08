#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll M = 2E5;
    vector<ll> P;
    P.push_back(0);
    P.push_back(1);
    P.push_back(3);
    P.push_back(2);
    ll LL=23;
    vector<ll> ind(LL);
    vector<ll> mx(LL);
    ind[0] = 0; mx[0]=0;
    ind[1] = 1; mx[1]=1;
    ind[2] = 3; mx[2]=3;
    ll k = 2;
    ll cmx=0;
    for(ll k=3; k<LL; k++) {
        ll sm = 1ll << (k-1);
        rep(i,ind[k-1]+1) {
            P.push_back(P[i] + sm);
            chmax(cmx, P[i] + sm);
        }
        ind[k] = P.size()-1;
        mx[k] = cmx;
    }
    ll T; cin>>T;
    while(T--) {
        ll N; cin>>N;
        auto it = lower_bound(mx.begin(), mx.end(), N) - mx.begin();
        ll k = ind[it];
        for(int i=1; i<=k; i++) {
            if(P[i] <= N) cout<<P[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}