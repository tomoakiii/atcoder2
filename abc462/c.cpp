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
    vector<pair<ll,ll>> A(N);
    rep(i,N) cin>>A[i].first>>A[i].second;
    sort(A.begin(),A.end());
    fenwick_tree<ll> FT(N+1);
    ll ans=0;
    for(auto [x,y]:A) {
        if(FT.sum(0,y) == 0)ans++;
        FT.add(y,1);
    }
    cout<<ans<<endl;
    return 0;
}