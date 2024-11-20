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
    cin >> N >> M;
    vector xy(N, vector<int>{});
    vector<int> inp(N);
    rep(i,M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        xy[u].push_back(v);
        inp[v]++;
    }
    queue<int> que;
    rep(i, N) {
        if (inp[i] == 0) que.push(i);
    }
    int cnt = 0;
    vector<int> ans(N);
    while(!que.empty()) {
        if (que.size() > 1){
            cout << "No" << endl;
            return 0;
        }
        int q = que.front();
        que.pop();
        ans[q] = cnt++;
        for(auto nx: xy[q]) {
            inp[nx]--;
            if (inp[nx] == 0) que.push(nx);
        }
    }
    cout<<"Yes"<<endl;
    //reverse(ans.begin(), ans.end());
    for(auto a:ans) cout<<a+1<<" ";
    cout << endl;
    return 0;
}