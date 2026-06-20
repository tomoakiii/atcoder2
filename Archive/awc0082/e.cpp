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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<ll>A(N);
    rep(i,N)cin>>A[i];
    vector uv(N,vector<int>{});
    rep(i,N-1) {
        ll p; cin>>p; p--;
        uv[p].push_back(i+1);
    }
    vector<int> root;
    vector<pair<int,int>> ord(N);
    vector<bool> visit(N);
    auto dfs = [&](auto dfs, int cur)->void{
        visit[cur]=true;
        root.push_back(cur);
        ord[cur].first = root.size()-1;
        for(auto nx:uv[cur]){
            if(visit[nx])continue;
            dfs(dfs,nx);
        }
        root.push_back(cur);
        ord[cur].second = root.size()-1;
    };
    dfs(dfs,0);
    ll M = root.size();
    int rN = sqrt(M);
    int K = (M+rN-1)/rN;
    struct S{
        vector<ll> st;
        int b;
        int e;
    };
    vector<S> vs(rN);
    int id=0;
    rep(i,rN){
        vs[i].b = id;
        rep(j,K){
            if(id<M) {
                int r = root[id++];
                vs[i].st.push_back(A[r]);
            }
        }
        sort(vs[i].st.begin(),vs[i].st.end());
        vs[i].e = id-1;
    }

    while(Q--){
        int query; cin>>query;
        int v; cin>>v; v--;
        auto [fr,sc] = ord[v];
        if(query == 1){
            ll oldA=A[v];
            ll x; cin>>x; A[v]=x;
            rep(i,rN) {
                if(vs[i].b <= fr && fr <= vs[i].e) {
                    auto it = lower_bound(vs[i].st.begin(), vs[i].st.end(),oldA) - vs[i].st.begin();
                    vs[i].st[it] = x;
                    sort(vs[i].st.begin(),vs[i].st.end());
                }
                if(vs[i].b <= sc && sc <= vs[i].e) {
                    auto it = lower_bound(vs[i].st.begin(), vs[i].st.end(),oldA) - vs[i].st.begin();
                    vs[i].st[it] = x;
                    sort(vs[i].st.begin(),vs[i].st.end());
                }
            }
        } else {
            ll ans=0;
            rep(i,rN){
                if(vs[i].e < fr)  continue;
                if(vs[i].b<=fr && fr<=vs[i].e) {
                    for(auto j=fr;j<=min(vs[i].e,sc);j++) {
                        if(A[root[j]] > A[v])ans++;
                    }
                    continue;
                }
                if(vs[i].b<=sc && sc<=vs[i].e){
                    for(auto j=vs[i].b; j<=sc; j++) {
                        if(A[root[j]] > A[v])ans++;
                    }
                    break;
                }
                if(vs[i].b > sc)  break;

                auto it = upper_bound(vs[i].st.begin(),vs[i].st.end(),A[v])-vs[i].st.begin();
                ans += vs[i].st.size() - it;


            }
            cout<<ans/2<<endl;
        }
    }
    return 0;
}