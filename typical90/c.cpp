#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector uv(N, vector<int>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    int mx = 0, mxid;
    auto f=[&](auto f, int cur, int pre, int d)->void{
        if(d > mx) {
            mxid = cur;
            mx = d;
        }
        for(auto nx: uv[cur]){
            if(nx == pre) continue;
            f(f, nx, cur, d+1);
        }
    };
    f(f, 0, -1, 0);
    int st = mxid;
    mx = 0, mxid;   
    f(f, st, -1, 0);
    cout << mx+1 << endl;
    return 0;
}