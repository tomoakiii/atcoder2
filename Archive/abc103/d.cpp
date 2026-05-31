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
    ll N,M;
    cin >> N >> M;
    vector<pair<int,int>> BA(M);
    rep(i,M)cin>>BA[i].second>>BA[i].first;
    sort(BA.begin(), BA.end());
    int last = -1;
    int ans = 0;
    for(auto [b,a]: BA) {
        if(a >= last) {
            last = b;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}