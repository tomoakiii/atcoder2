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
typedef pair<ll,ll> pll;
int main(){
    ll N,X,Y;
    cin >> N>>X>>Y;
    vector<pair<pll,pll>> vp;
    vp.push_back({{0,0}, {X,Y}});
    rep(i,N) {
        char c; cin>>c;
        ll A,B; cin>>A>>B;
        vector<pair<pll, pll>> vp2;
        if(c == 'X') {
            for(auto [v1, v2]: vp) {
                if(v1.first < A && v2.first-1 >= A) {
                    vp2.push_back({{v1.first, v1.second - B}, {A, v2.second - B}});
                    vp2.push_back({{A, v1.second + B}, {v2.first, v2.second + B}});
                } else if (v1.first >= A) {
                    vp2.push_back({{v1.first, v1.second + B}, {v2.first, v2.second + B}});
                } else {
                    vp2.push_back({{v1.first, v1.second - B}, {v2.first, v2.second - B}});
                }
            }
        } else {
            for(auto [v1, v2]: vp) {
                if(v1.second < A && v2.second-1 >= A) {
                    vp2.push_back({{v1.first - B, v1.second}, {v2.first - B, A}});
                    vp2.push_back({{v1.first + B, A}, {v2.first + B, v2.second}});
                } else if (v1.second >= A) {
                    vp2.push_back({{v1.first + B, v1.second}, {v2.first + B, v2.second}});
                } else {
                    vp2.push_back({{v1.first - B, v1.second}, {v2.first - B, v2.second}});
                }
            }
        }
        swap(vp2, vp);
    }
    int sz = vp.size();
    vector<ll> scale(sz);
    rep(i,sz) {
        auto [v1, v2] = vp[i];
        scale[i] = (v2.first - v1.first) * (v2.second - v1.second);
    }
    dsu UF(sz);
    rep(i, sz) {
        for(int j=i+1; j<sz; j++) {
            auto [vi1, vi2] = vp[i];
            auto [vj1, vj2] = vp[j];
            if(vi2 == vj1) continue;
            if(vj2 == vi1) continue;
            if(vi2.second == vj1.second && vj2.first == vi1.first) continue;
            if(vi2.first == vj1.first && vj2.second == vi1.second) continue;
            if(vi2.first < vj1.first) continue;
            if(vj2.first < vi1.first) continue;
            if(vi2.second < vj1.second) continue;
            if(vj2.second < vi1.second) continue;
            UF.merge(i,j);
        }
    }
    vector<ll> ans{};
    for(auto g: UF.groups()){
        ll sm = 0;
        for(auto gg: g) {
            sm += scale[gg];
        }
        ans.push_back(sm);
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(auto a: ans) cout<<a<<" ";
    cout<<endl;
    return 0;
}