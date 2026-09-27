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
    ll N,D;
    cin >> N >> D;
    ll tot = 0;
    vector<ll> X(N),P(N);
    rep(i,N) {
        cin>>X[i]>>P[i];
        tot+=P[i];
    }
    ll r=0,sm=0;
    ll ans=0;
    rep(i,N){
        while(r<N && X[i]+D-1>=X[r]){
            sm+=P[r++];
        }
        chmax(ans,sm);
        sm-=P[i];        
    }
    cout<<tot-ans<<endl;
    return 0;
}