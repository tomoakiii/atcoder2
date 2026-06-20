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

    vector ans(N,vector<int>{});
    rep(i,N) {
        ll K; cin>>K;
        rep(j,K) {
            ll a; cin>>a; a--;
            ans[a].push_back(i+1);
        }
    }
    for(auto aa:ans){
        ll s = aa.size();
        cout<<s<<" ";
        for(auto a:aa) cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}