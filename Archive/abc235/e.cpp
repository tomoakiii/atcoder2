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
typedef pair<ll, int> pli;
int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    struct st{
        int to;
        ll c;
        int ind;
    };
    dsu UF(N);
    vector<pair<ll,int>> vec(M+Q);
    vector<pair<int,int>> node(M+Q);
    rep(i,M) {
        ll a, b, c;
        cin>>a>>b>>c;
        a--, b--;        
        node[Q+i] = {a,b};
        vec[Q+i] = {c, Q+i};
    }
    rep(i,Q) {
        ll a, b, c;
        cin>>a>>b>>c;
        a--, b--;        
        node[i] = {a,b};
        vec[i] = {c,i};
    }
    sort(vec.begin(), vec.end());
    vector<bool> ans(Q);
    for(auto [c, i] : vec) {
        auto [a,b] = node[i];
        if(i>=Q) {
            if(!UF.same(a,b)) UF.merge(a,b);
        } else {
            if(!UF.same(a,b)) ans[i] = true;
            else ans[i] = false;
        }        
    }
    rep(i,Q) {
        cout << (ans[i]?"Yes":"No") << endl;
    }

    return 0;
}