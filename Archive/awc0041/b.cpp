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
    ll N, M;
    cin >> N >> M;
    vector<ll> W(M-1);
    rep(i,M-1) cin>>W[i];
    ll mx=0;
    rep(i,M-1) {
        chmax(mx,W[i]);
        W[i]=mx;
    }
    rep(i,N) {
        ll b; cin>>b;
        auto it=lower_bound(W.begin(),W.end(),b+1)-W.begin();
        cout<<it+1<<endl;
    }
    return 0;
}