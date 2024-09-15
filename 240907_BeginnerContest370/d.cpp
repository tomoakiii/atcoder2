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
    ll H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> BmbH(H), BmbW(W);
    ll ans = H*W;
    while(Q--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        if(BmbH[a].find(b) == BmbH[a].end()){
            BmbH[a].insert(b);
            BmbW[b].insert(a);
            ans--;
            continue;
        }
        int nxl = distance(lower_bound(BmbH[a].begin(), BmbH[a].end(), b), BmbH[a].begin())-1;
        if(nxl==-1) nxl=-INFi;
        int nxu = distance(upper_bound(BmbH[a].begin(), BmbH[a].end(), b), BmbH[a].begin());
        if(nxu==N) nxu=INFi;
        int nyl = distance(lower_bound(BmbW[b].begin(), BmbW[b].end(), a), BmbW[b].begin())-1;
        if(nyl==-1) nyl=-INFi;
        int nyu = distance(upper_bound(BmbW[b].begin(), BmbW[b].end(), a), BmbW[b].begin());
        if(nyu==N) nyu=INFi;
        vector<pair<int, pair<int,int>>> dxy{};
        dxy.push_back({b-nxl, {a, nxl}});
        dxy.push_back({nxu-b, {a, nxu}});
        dxy.push_back({a-nyl, {nyl, b}});
        dxy.push_back({nyu-a, {nyl, b}});
        sort(dxy.begin(), dxy.end());
        int d = dxy[0].first;
        rep(k, dxy.size()) {
            if(dxy[k].first != d) break;
            ans--;
            BmbH[dxy[k].second.first].insert(dxy[k].second.second);
            BmbW[dxy[k].second.second].insert(dxy[k].second.first);
        }
    }
    cout << ans << endl;
    return 0;
}