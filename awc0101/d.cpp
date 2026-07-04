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
    ll N;
    cin >> N;
    vector<ll> g(N),H(N),W(N);
    rep(i,N) {
        ll h,w,S; cin>>h>>w>>S;
        g[i]=h*w/S;
        H[i]=h,W[i]=w;
    }
    ll gc=H[0];
    rep(i,N){
        gc=gcd(gc,H[i]);
        gc=gcd(gc,W[i]);
    }
    map<ll,ll> mp;
    for(ll i=2;i<=gc;i++){
        if(g[0]==1) break;
        if(W[0]%i != 0) continue;
        if(H[0]%i != 0) continue;
        while(g[0]%i==0) {
            g[0]/=i;
            mp[i]++;
        }
    }
    for(int i=1; i<N;i++){
        auto it=mp.begin();
        while(it != mp.end()){
            ll cnt=0;
            ll x=it->first;
            while(g[i]%x == 0) {
                g[i]/=x;
                cnt++;
            }
            chmin(it->second,cnt);
            it++;
        }
    }
    ll ans=1;
    for(auto [x,c]:mp){
        rep(i,c/2)ans*=x;
    }
    cout<<ans<<endl;
    return 0;
}