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
    sort(L.begin(),L.end());
    rep(i,M) cin>>R[i];
    sort(R.rbegin(),R.rend());
    ll rsm=0;
    vector<ll> L2(N+1);
    rep(i,N) L2[i+1]=L2[i]+L[i];
    int r=0;
    rep(j,M) {
        rsm+=R[j];
        ll k=j+1;
        while(r<N && L[r]<k) {
            r++;
        }
        ll p = (N-r)*k + L2[r];
        if(p < rsm){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}