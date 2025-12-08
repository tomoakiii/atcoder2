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
    ll N,K; cin>>N>>K;
    ll mx = (N-1)*(N-2)/2;
    if(K > mx) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int,int>> ans;
    rep(i,N-1) {
        ans.push_back({0,i+1});
    }
    ll rm = mx - K;
    for(int i=1; i<=N-2; i++) for(int j=i+1; j<=N-1; j++) {
        if(rm == 0) break;
        ans.push_back({i,j});
        rm--;
    }
    cout<<ans.size()<<endl;
    for(auto [u,v]:ans) cout<<u+1<<" "<<v+1<<endl;
    return 0;
}