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
    struct node{
        int from;
        int to;
        int val;
    };
    vector uv(N, vector<int>{});        
    vector<int> in(N);
    rep(i,M) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        uv[a].push_back(b);
        in[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> que;
    rep(i,N) if(in[i] == 0) que.push(i);
    vector<int> ans;    
    while(!que.empty()) {
        int q = que.top();
        que.pop();
        ans.push_back(q);
        for(auto i: uv[q]) {
            in[i]--;
            if(in[i] == 0) que.push(i);
        }
    }
    if(ans.size() != N) cout<<-1<<endl;
    else {
        for(auto a: ans) cout<<a+1<<" ";
        cout<<endl;
    }
    return 0;
}