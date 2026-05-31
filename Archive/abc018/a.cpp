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
    vector<pair<int,int>> v(3);
    rep(i,3) {
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v.rbegin(), v.rend());
    vector<int> ans(3);
    int cnt = 1;
    for(auto [val,i]: v) {
        ans[i] = cnt++;
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}