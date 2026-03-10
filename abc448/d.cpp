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
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    M=N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    unordered_set<ll> st;
    vector<bool> ans(N, false);
    auto func = [&](auto func, int cur, bool flg, int pre=-1)->void{
        if(st.contains(A[cur])) flg = true;
        else if (!flg){
            st.insert(A[cur]);
        }
        /*
        cerr << cur << "---" << endl;
        for(auto s:st) cerr << s << " " ;
        cerr << endl;
        */
        ans[cur] = flg;
        for(auto nx : uv[cur]) {
            if(nx == pre) continue;
            func(func, nx, flg, cur);
        }
        if(!flg) st.erase(A[cur]);
    };
    func(func, 0, false, -1);
    for(auto a:ans) {
        if(a) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}