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
    vector<ll> D(N);
    ll pv=6e4, nv=-6e4;
    //ll pv=10, nv=-10;
    rep(i,N)cin>>D[i];
    rep(i,M){
        ll x;cin>>x;
        if(x>0)chmin(pv,x);
        else if(x<0)chmax(nv,x);
        else {
            cout<<0<<endl;
            return 0;
        }
    }

    bitset<100010> vec,mask;
    int offs=50005;
    rep(i,100010) {
        if(i-offs > nv && i-offs < pv) mask[i]=1;
    }
    vec[offs]=1;
    rep(i,N){
        ll d=D[i];
        if(d>0) {
            vec|=(vec<<d);
        } else {
            vec|=(vec>>(-d));
        }
        vec&=mask;
    }
    for(int i=100009; i>=0; i--) {
        if(vec[i]) {
            cout<<i-offs<<endl;
            return 0;
        }
    }
    return 0;
}