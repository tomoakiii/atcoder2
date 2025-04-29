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
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
int main(){
    ll N;
    cin >> N;
    unordered_map<ll, int> mp;
    vector PE(N, vector<pl>{});
    vector<pl> nm(2e5+1);
    int ind = 0;
    rep(i,N) {
        int m;
        cin >> m;
        PE[i].resize(m);
        rep(j,m) {
            ll p, e;
            cin >> p >> e;            
            int id;
            if(mp.contains(p)) id = mp[p];
            else {
                id = ind;
                ind++;
                mp[p] = id;
            }
            PE[i][j] = {id,e};
            if(nm[id].first == e) nm[id].second++;
            else if (nm[id].first < e) {
                nm[id].first = e;
                nm[id].second = 1;
            }
        }
    }
    set<vector<int>> st;
    ll ans = 0;
    bool flg = false;
    rep(i,N) {
        vector<int> v{};
        for(auto [id, e]: PE[i]) {
            if(nm[id].first == e && nm[id].second == 1) v.emplace_back(id);
        }
        if(v.empty()) {
            if(!flg) {
                ans++;
                flg = true;
            }
            continue;
        }
        sort(v.begin(), v.end());
        if(st.contains(v)) continue;
        else {
            st.insert(v);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}