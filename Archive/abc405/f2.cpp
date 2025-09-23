#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

/* Euler Tour + Segment Tree for LCA */
class eular_tour {
private:
    vector<int> first_appear;     // 各ノードの最初の出現位置
    vector<int> depth;            // Euler Tour 上の深さ
    vector<int> eular_tour_node;  // Euler Tour 上のノード番号

    struct val_ind {
        int v; // depth
        int i; // index in euler_tour
    };
    val_ind min(val_ind a, val_ind b) {
        return (a.v <= b.v ? a : b);
    }
    val_ind max(val_ind a, val_ind b) {
        return (a.v >= b.v ? a : b);
    }

    int n, sz, trsize;
    struct nd {
        int l, r, c;
        val_ind min, max;
        int val;
    };
    vector<nd> tr;

public:
    // コンストラクタ
    eular_tour(vector<vector<int>> &tree) {
        int N = tree.size();
        first_appear.assign(N, -1);  // ノード数で確保
        depth.clear();
        eular_tour_node.clear();

        // DFS
        auto dfs = [&](auto self, int cur, int d) -> void {
            assert(cur >= 0 && cur < (int)first_appear.size());
            if (first_appear[cur] == -1) {
                first_appear[cur] = (int)depth.size();
            }
            depth.push_back(d);
            eular_tour_node.push_back(cur);

            for (auto nx : tree[cur]) {
                self(self, nx, d + 1);
                depth.push_back(d);
                eular_tour_node.push_back(cur);
            }
        };
        dfs(dfs, 0, 0);

        // Segment Tree 構築
        sz = (int)depth.size();
        n = 1;
        while (n < sz) n *= 2;
        trsize = 2 * n - 1;
        tr.resize((size_t)trsize);

        for (int i = 0; i < sz; i++) {
            tr[i + n - 1].val = tr[i + n - 1].max.v = tr[i + n - 1].min.v = depth[i];
            tr[i + n - 1].max.i = tr[i + n - 1].min.i = i;
        }
        for (int i = 0; i < n; i++) tr[i + n - 1].l = tr[i + n - 1].r = tr[i + n - 1].c = i;

        int k = 1;
        while ((n - 1) / k > 0) {
            for (int i = (n - 1) / k; i < (trsize - 1) / k; i += 2) {
                tr[i / 2].max = max(tr[i].max, tr[i + 1].max);
                tr[i / 2].min = min(tr[i].min, tr[i + 1].min);
                tr[i / 2].val = tr[i].val + tr[i + 1].val;
            }
            k *= 2;
        }
        for (int i = n - 2; i >= 0; i--) {
            tr[i].l = tr[i * 2 + 1].l;
            tr[i].r = tr[i * 2 + 2].r;
            tr[i].c = (tr[i].l + tr[i].r) / 2;
        }
    }

    // LCA
    int least_common_ancestor(int a, int b) {
        int fa = first_appear[a], fb = first_appear[b];
        if (fa > fb) swap(fa, fb);
        auto v = this->MinElement(0, fa, fb);
        return eular_tour_node[v.i];
    }

    // ノード間距離
    int distance(int a, int b) {
        int fa = first_appear[a], fb = first_appear[b];
        if (fa > fb) swap(fa, fb);
        auto v = this->MinElement(0, fa, fb);
        return (depth[fa] - v.v + depth[fb] - v.v);
    }

    // Segment Tree の Min クエリ
    val_ind MinElement(int ind, int a, int b) {
        if (tr[ind].l == a && tr[ind].r == b) return tr[ind].min;
        if (tr[ind].c >= a && tr[ind].c < b) {
            return min(MinElement(2 * ind + 1, a, tr[ind].c),
                       MinElement(2 * ind + 2, tr[ind].c + 1, b));
        }
        if (tr[ind].c >= b) return MinElement(2 * ind + 1, a, b);
        return MinElement(2 * ind + 2, a, b);
    }
};





int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<int,int>> AB(M+1);
    AB[0] = {0, 2*N+2};
    rep(i,M) cin>>AB[i+1].first>>AB[i+1].second;
    sort(AB.begin(), AB.end());
    vector tree(M+1, vector<int>{});
    vector<int> par(M+1,-1);    
    for(int cur = 1; cur <= M; cur++){
        int r = AB[cur].second;
        int rr = AB[cur-1].second;        
        if(rr > r) {
            par[cur] = cur-1;
            tree[cur-1].push_back(cur);
        } else {
            int from = par[cur];
            while(AB[from].second < r) {
                from = par[from];
            }
            par[cur] = from;
            tree[from].push_back(cur);
        }
    }

    vector<int> index(2*N+2, -1);
    int p = 0;
    auto func = [&](auto func, int cur)->void{
        if( tree[cur].empty() ) {
            for(int i=AB[cur].first; i<=AB[cur].second; i++) {
                index[i] = cur;                
            }
            return;
        }
        for(int i=AB[cur].first; i<AB[tree[cur][0]].first; i++) {
            index[i] = cur;
        }
        int sz = tree[cur].size();
        for(auto nx: tree[cur]){
            func(func, nx);
        }
        for(int i=AB[tree[cur][sz-1]].second; i<=AB[cur].second; i++) {
            index[i] = cur;
        }        
    };
    func(func, 0);
    eular_tour et(tree);
    int Q; cin>>Q;
    while(Q--) {
        int c,d; cin>>c>>d;
        int cind = index[c];
        int dind = index[d];
        int e = et.distance(cind, dind);
        cout << e << endl;
    }
    return 0;
}