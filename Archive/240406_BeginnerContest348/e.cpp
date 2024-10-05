#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N;
    cin >> N;
    int a,b;
    vector<vector<int>> nodes(N);
    for (int i=0; i<N-1; i++){
        cin >> a >> b;
        a--; b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    struct node{
        ll C;
        ll Csum;
    };
    vector<node> tree(N);
    ll Csum=0;
    for (int i=0; i<N; i++){
        cin >> tree[i].C;
        tree[i].Csum = tree[i].C;
        Csum += tree[i].C;
    }
    
    int cntr=-1;
    auto dfs = [&](auto dfs, int q, int p) -> ll {
        ll mx = 0;
        for (int nn : nodes[q]){
            if (nn != p){
                ll d = dfs(dfs, nn, q);
                mx = max(d, mx);
                tree[q].Csum += d;
            }
        }
        mx = max(mx, Csum - tree[q].Csum);
        if (mx*2 <= Csum) cntr = q;
        return tree[q].Csum;
    };
    dfs(dfs, 0, -1);

    ll ans=0;
    auto dfs2 = [&](auto dfs2, int q, ll dist, int p) -> void {
        ans += dist * tree[q].C;
        for (int nn : nodes[q]){
            if (nn != p) {
                dfs2(dfs2, nn, dist+1, q);
            }
        }
    };
    dfs2(dfs2, cntr, 0, -1);

    cout << ans << endl;
    return 0;
}

