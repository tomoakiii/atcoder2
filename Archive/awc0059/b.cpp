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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> T(M);
    rep(i,M) cin>>T[i];
    vector<ll> P(N);
    rep(i,N) {
        bool flg=true;
        rep(j,M) {
            ll s; cin>>s;
            P[i]+=s;
            if(s < T[j]) flg=false;
        }
        if(!flg) P[i]=-1;
    }
    auto P2 = P;
    sort(P2.rbegin(), P2.rend());
    ll th = 0;
    chmax(th, P2[K-1]);
    rep(i,N) {
        if(P[i] >= th) cout<<i+1<<endl;
    }
    return 0;
}