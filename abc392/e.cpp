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
    vector<pair<int,int>> AB(M);
    rep(i,M) {
        cin>>AB[i].first>>AB[i].second;
        AB[i].first--, AB[i].second--;
    }
    
    dsu UF(N);
    vector<int> pool{};
    rep(i,M) {
        if(UF.leader(AB[i].first) == UF.leader(AB[i].second)) {
            pool.emplace_back(i);
        } else {
            UF.merge(AB[i].first, AB[i].second);
        }
    }
    set<int> ld;
    rep(i,N) {
        ld.insert(UF.leader(i));
    }
    vector<pair<int,int>> ans{};
    rep(i, pool.size()) {        
        if(ld.size() > 1) {
            auto it = ld.begin();
            if( UF.leader(*it) == UF.leader(AB[pool[i]].first) ){
                it++;
            }
            int l = *it;
            ans.push_back({pool[i], l});            
            ld.erase(l);
            UF.merge(AB[pool[i]].first, l);
        }
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i].first+1 << " " << AB[ans[i].first].first + 1 << " " << ans[i].second+1 << endl;
    }
    return 0;
}