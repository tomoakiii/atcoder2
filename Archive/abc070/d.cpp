#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define ALLOCSIZE 2000000
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

class SegTree {
private:
    struct val_ind{
        int v,i;
    };
    val_ind min(val_ind a, val_ind b) {
        if (a.v <= b.v) return a;
        else return b;
    }
    int n, sz, trsize;
    struct nd{
        int l,r,c,val;
        val_ind min;
    };
    vector<nd> tr;
public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    SegTree() {}

    void refresh(vector<int> &v){
        sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize);
        for(int i=0; i<sz; i++) {
            tr[i+n-1].val = tr[i+n-1].min.v = v[i];
            tr[i+n-1].min.i = i;
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                tr[i/2].min = min(tr[i].min, tr[i+1].min);
                tr[i/2].val = tr[i].val + tr[i+1].val;
            }
            k*=2;
        }
        for(int i=n-2; i>=0; i--) {
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;
        }
    }


    // MinElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    val_ind MinElement(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b){
            return tr[ind].min;
        }
        if (tr[ind].c >= a && tr[ind].c < b) {
            return min(MinElement(2*ind+1, a, tr[ind].c),
                       MinElement(2*ind+2, tr[ind].c + 1, b));
        }
        if (tr[ind].c >= b) return MinElement(2*ind+1, a, b);
        return MinElement(2*ind+2, a, b);
    }
};



/*
共通祖先を探したり、ノードの間の距離を求めたりする
uv : pair<int,Type> 型でtree形式のものを入力として入れる
root : treeの根
*/
template <class Type> class Tree_Analyzer{
    public:
    vector<int> first_appear;
    vector<int> depth_eur; // ノードごとの距離（隣接ノードは距離1とする）
    vector<Type> dist; // ノードごとの距離（辺の重みの和）
    vector<int> eular_tour_node;
    SegTree sg;
    typedef pair<int, Type> pil;

    Tree_Analyzer(vector<vector<pil>> &uv, int root) {
        int N=uv.size();
        dist.resize(N);
        auto dfs = [&](auto dfs, int cur, int pre, int d, Type dd)->void{
            depth_eur.push_back(d);
            eular_tour_node.push_back(cur);
            dist[cur] = dd;
            for(auto [nx,w]: uv[cur]){
                if(nx==pre)continue;
                dfs(dfs, nx, cur, d+1, dd+w);
                depth_eur.push_back(d);
                eular_tour_node.push_back(cur);
            }
        };
        dfs(dfs, root, -1, 0, 0);
        first_appear.resize(N, -1);
        rep(i, eular_tour_node.size()) {
            if(first_appear[eular_tour_node[i]] == -1) {
                first_appear[eular_tour_node[i]] = i;
            }
        }
        sg.refresh(depth_eur);
    }

    // 共通祖先のインデックス番号を返す
    // aとbはtreeのノード番号
    int least_common_ancestor(int a, int b){
        int fa = first_appear[a], fb = first_appear[b];
        if(fa>fb) swap(fa,fb);
        auto v = sg.MinElement(0, fa, fb);
        return eular_tour_node[v.i];
    }

    // 木のノード間距離を返す
    // aとbはtreeのノード番号
    ll get_distance(int u, int v){
        int lca = this->least_common_ancestor(u,v);
        return abs(dist[lca] - dist[u]) + abs(dist[lca] - dist[v]);
    }

};


int main(){
    int N;
    cin >> N;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,N-1) {
        int u,v;
        ll d;
        cin>>u>>v>>d;
        u--, v--;
        uv[u].emplace_back(v,d);
        uv[v].emplace_back(u,d);
    }
    Tree_Analyzer<ll> TA(uv,0);
    ll Q,K; cin>>Q>>K; K--;
    while(Q--) {
        ll x, y; cin>>x>>y; x--, y--;
        cout << TA.get_distance(x,K) + TA.get_distance(y,K) << endl;
    }
    return 0;
}
