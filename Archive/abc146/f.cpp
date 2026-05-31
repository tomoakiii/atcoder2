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
typedef pair<int,int> pii;

int main(){
    ll N,M; string S;
    cin >> N >> M >> S;
    set<int> st;
    rep(i,N+1) {
        if(S[i]=='0') st.insert(i);
    }
    st.insert(INFi);
    vector<int> pre(N+1,-1);
    vector<int> scv(N+1,INFi);
    scv[0] = 0;
    bool flg = true;
    priority_queue<pii,vector<pii>,greater<pii>> que;
    que.push({0,0});
    st.erase(0);
    while(!que.empty()) {
        auto [v,q] = que.top();
        que.pop();
        if(scv[q] < v) continue;
        auto it = st.lower_bound(q);
        while(*it <= q+M && *it > q) {
            int p = *it;
            if(!chmin(scv[p], scv[q] + 1)) {
                continue;
            }
            pre[p] = q;
            if(p == N) {
                int s = N;
                vector<int> ans;
                while(s != 0) {
                    ans.push_back(s-pre[s]);
                    s = pre[s];
                }
                reverse(ans.begin(),ans.end());
                for(auto a:ans) cout<<a<<" ";
                cout<<endl;
                return 0;
            }
            it = st.erase(it);
            // it++;
            que.push({v+1, p});
        }
    }

    cout << -1 << endl;
    return 0;
}