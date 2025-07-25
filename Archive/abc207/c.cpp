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
    ll N;
    cin >> N;
    vector<pair<ll,ll>> v(N);
    rep(i,N) {
        int t; cin>>t;
        ll l,r; cin>>l>>r;
        if(t==1) v[i] = {10*l,10*r};
        if(t==2) v[i] = {10*l,10*r-1};
        if(t==3) v[i] = {10*l+1,10*r};
        if(t==4) v[i] = {10*l+1,10*r-1};
    }
    ll cnt=0;
    rep(i,N) for(int j=i+1; j<N; j++) {
        if (!(v[i].second < v[j].first || v[j].second < v[i].first))cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}