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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll D,N; cin>>D>>N;
    vector<pair<ll, pair<ll,ll>>>LRH(N);
    rep(i,N) cin>>LRH[i].second.first >> LRH[i].second.second>>LRH[i].first;
    sort(LRH.rbegin(),LRH.rend());
    vector<ll> ans(D,24);
    for(auto [h, lr]: LRH) {
        auto [l,r] = lr;
        l--, r--;
        for(int i=l; i<=r; i++) ans[i] = h;
    }
    ll sm = 0;
    for(auto a:ans)sm += a;
    cout <<sm << endl;
    return 0;
}