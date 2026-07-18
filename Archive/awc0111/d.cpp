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
    ll N, M;
    cin >> N;
    M = N-1;

    unordered_set<string> tmp1, tmp2;
    rep(kkk, 2){
        vector uv(N, vector<ll>{});
        rep(i,M) {
            int u,v;
            cin>>u>>v;
            u--, v--;
            uv[u].emplace_back(v);
            uv[v].emplace_back(u);
        }
        auto dfs = [&](auto dfs, int cur, int pre)->unordered_set<string>{
            vector<unordered_set<string>> sts;
            for(auto nx : uv[cur]){
                if(nx == pre) continue;
                sts.push_back(dfs(dfs, nx, cur));
            }
            int sz = sts.size();

            vector<int> ord(sz);
            rep(i,sz) ord[i]=i;
            unordered_set<string> ret;
            do{
                unordered_set<string> st;
                st.insert("");
                rep(i,sz){
                    unordered_set<string> st2;
                    for(auto s : sts[ord[i]]){
                        for(auto s2 : st) {
                            st2.insert(s2 + s);
                        }
                    }
                    swap(st, st2);
                }
                for(auto s:st){
                    ret.insert("a" + s + "b");
                }
            }while(next_permutation(ord.begin(), ord.end()));
            return ret;
        };
        tmp1 = dfs(dfs, 0, -1);
        swap(tmp1, tmp2);
    }
    set<string> st;
    for(auto s:tmp1){
        if(tmp2.contains(s)) st.insert(s);
    }
    cout<<st.size()<<endl;
    for(auto s:st) cout<<s<<endl;
    return 0;
}