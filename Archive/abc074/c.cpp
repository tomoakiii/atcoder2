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
    ll A,B,C,D,E,F; cin>>A>>B>>C>>D>>E>>F;
    ll p = F/(100+E);
    set<pair<ll,ll>> st;
    st.insert({0,0});
    queue<pair<ll,ll>> que;
    que.push({0,0});
    pair<double,pair<ll,ll>> ans = {0,{0,0}};
    while(!que.empty()) {
        auto [w, s] = que.front();
        que.pop();
        auto judge = [&](ll wat, ll sug)->void{
            if(st.contains({wat,sug})) return;
            if(wat*100 + sug <= F && wat*E >= sug) {
                st.insert({wat,sug});
                que.push({wat,sug});
                double pec = (double)sug/(double(100*wat + sug));
                chmax(ans, {pec, {100*wat+sug,sug}});
            }
        };
        judge(w+A, s);
        judge(w+B, s);
        judge(w, s+C);
        judge(w, s+D);
    }

    cout<<ans.second.first<<" "<<ans.second.second<<endl;
    return 0;
}