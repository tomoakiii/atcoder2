#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;

    vector tr(N, vector<ll>{});
    int u,v;
    rep(i, N-1) {
        cin >> u >> v;
        u--; v--;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    int longest;
    int it = 0;
    int mx = 0;
    auto f = [&](auto f, int cur, int from, int dist)->void{
        if(dist > mx) {
            mx = dist;
            longest = cur;
        }
        for(auto k: tr[cur]){
            if(k == from) continue;
            f(f, k, cur, dist+1);
        }
    };
    f(f, 0, -1, 0);

    vector<int> ans;
    auto f2 = [&](auto f2, int cur, int from)->void{
        int node;
        for(auto k: tr[cur]){
            if(k == from) continue;
            node = k;
            ans.push_back(tr[node].size());
        }
        for(auto k: tr[node]){
            if(k == cur) continue;
            if(tr[k].size() == 1) continue;
            for(auto k2: tr[k]){            
                if(k2 == node) continue;
                f2(f2, k2, k);
            }
        }
    };
    f2(f2, longest, -1);

    sort(ans.begin(), ans.end());
    for(auto a:ans) cout << a << " ";
    cout << endl;
    return 0;
}