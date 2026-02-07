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

int main() {
    int N,M; cin>>N>>M;
    vector<int> U(M),V(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        U[i]=u, V[i]=v;
    }
    dsu UF(N);
    int Q; cin>>Q;
    vector query(Q,vector<int>{});
    set<int> st;
    rep(i,Q) {
        int q; cin>>q;
        query[i].emplace_back(q);
        if(q==1) {
            int x; cin>>x; x--;
            query[i].emplace_back(x);
            st.insert(x);
        }else {
            int s,t; cin>>s>>t; s--;t--;
            query[i].emplace_back(s);
            query[i].emplace_back(t);
        }
    }
    rep(i,M) {
        if(st.contains(i)) continue;
        UF.merge(U[i],V[i]);
    }
    reverse(query.begin(),query.end());
    vector<bool> ans;
    for(auto v:query){
        if(v[0] == 1) {
            int x = v[1];
            UF.merge(U[x],V[x]);
        } else {
            if(UF.same(v[1],v[2])) ans.push_back(true);
            else ans.push_back(false);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto a:ans) if(a) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    cout << endl;
}