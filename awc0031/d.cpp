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
ll op(ll a, ll b) {return a+b;}
ll e() {return 0;}
ll id(){return 0;}
ll mapping(ll a, ll b){return a+b;}
ll composition(ll a, ll b){return a+b;}

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> L(N),R(M);
    rep(i,N) cin>>L[i];
    sort(L.rbegin(),L.rend());
    rep(i,M) cin>>R[i];
    sort(R.rbegin(),R.rend());
    lazy_segtree<ll, op, e, ll, mapping, composition, id> ST(M);
    int st=0;
    rep(i,N) {
        int r = st+L[i];
        if(r>M) r=M;
        ST.apply(st,r,1);
        while(st < M && ST.get(st) >= R[st])st++;
        if(st>=M) break;
    }
    if(ST.get(M-1)>=R[M-1])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}