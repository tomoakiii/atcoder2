#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll H,W;
    cin >> H >> W;
    vector<pair<int,int>> ans;
    rep(i,H) {
        string S; cin>>S;
        rep(j,W) {
            if(S[j] == 'T') ans.push_back({i+1,j+1});
        }
    }
    cout<<ans.size()<<endl;
    for(auto [i,j]:ans) cout<<i<<" "<<j<<endl;
    return 0;
}