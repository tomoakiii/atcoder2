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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    vector<bool> visit(N,false);
    vector<int> loop(N,-1);
    set<int> st;
    auto dfs=[&](auto dfs, int cur, int d)->int{
        if(visit[cur]) {
            if(loop[cur]==-1) loop[cur] = cur;
            st.insert(loop[cur]);
            return loop[cur];
        }
        visit[cur]=true;
        loop[cur]=dfs(dfs, A[cur], d+1);
        return loop[cur];
    };
    rep(i,N) {
        if(!visit[i])dfs(dfs, i, 0);
    }
    vector<ll> ans(N);
    for(auto s:st) {
        int i = s;
        int sm = 0;
        while(A[i] != s) {
            sm++;
            i = A[i];
        }
        ans[s] = sm+1;
    }
    rep(i,N) {
        cout<<ans[loop[i]]<<" \n"[i==N-1];
    }
    return 0;
}