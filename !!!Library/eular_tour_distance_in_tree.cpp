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
        int v;
        int i;
    };
    val_ind min(val_ind a, val_ind b) {
        if (a.v <= b.v) return a;
        else return b;
    }
    val_ind max(val_ind a, val_ind b) {
        if (a.v >= b.v) return a;
        else return b;
    }

    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
        val_ind min, max;
        int val;
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
            tr[i+n-1].val = tr[i+n-1].max.v = tr[i+n-1].min.v = v[i];
            tr[i+n-1].max.i = tr[i+n-1].min.i = i;
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                tr[i/2].max = max(tr[i].max, tr[i+1].max);
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

    // MaxElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    val_ind MaxElement(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b) return tr[ind].max;
        if (tr[ind].c >= a && tr[ind].c < b) return
            max(MaxElement(2*ind+1, a, tr[ind].c),
                MaxElement(2*ind+2, tr[ind].c + 1, b));
        if (tr[ind].c >= b) return MaxElement(2*ind+1, a, b);
        return MaxElement(2*ind+2, a, b);   
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

    int GetVal(int ind){
        int i = ind+n-1;
        return tr[i].val;        
    }
    
    void SetVal(int ind, int val){
        int i = ind+n-1;
        tr[i].val = tr[i].min.v = tr[i].max.v = val;
        while(i>0){
            int ii = (i-1)/2;
            tr[ii].min = min(tr[ii*2+1].min, tr[ii*2+2].min);
            tr[ii].max = max(tr[ii*2+1].max, tr[ii*2+2].max);
            tr[ii].val = tr[ii*2+1].val + tr[ii*2+2].val;
            i = ii;
        }
    }

    void AddVal(int ind, int delta){
        int i = ind+n-1;
        tr[i].val = tr[i].min.v = tr[i].max.v = tr[i].val + delta;
        while(i>0){
            int ii = (i-1)/2;
            tr[ii].min = min(tr[ii*2+1].min, tr[ii*2+2].min);
            tr[ii].max = max(tr[ii*2+1].max, tr[ii*2+2].max);
            tr[ii].val = tr[ii*2+1].val + tr[ii*2+2].val;
            i = ii;
        }
    }

    int GetSum(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b){
            return tr[ind].val;
        }
        if (tr[ind].c >= a && tr[ind].c < b) {
            return GetSum(2*ind+1, a, tr[ind].c) +
                GetSum(2*ind+2, tr[ind].c + 1, b);
        }
        if (tr[ind].c >= b) return GetSum(2*ind+1, a, b);
        return GetSum(2*ind+2, a, b);
    }

    void DispTree() {
        int ind = 0;
        int nx = 1;
        while(ind < trsize) {
            for(int i=0; i < nx; i++) {
                cout << ind << "(" << tr[ind].l << "-" << tr[ind].r << "):" << tr[ind].val << ", ";
                ind++;
            }
            cout << endl;
            nx *= 2;
        }
        cout << endl;
    }
};



class eular_tour{
    public:
    vector<int> first_appear;
    vector<int> depth;
    vector<int> eular_tour_node;
    SegTree sg;
    eular_tour(vector<vector<int>> &tree) {
        auto dfs = [&](auto dfs, int cur, int d)->void{                                    
            depth.push_back(d);
            eular_tour_node.push_back(cur);
            first_appear.push_back(eular_tour_node.size() - 1);
            for(auto nx: tree[cur]){             
                dfs(dfs, nx, d+1);
                depth.push_back(d);                
                eular_tour_node.push_back(cur);
            }            
        };
        dfs(dfs, 0, 0);
        sg.refresh(depth);
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
    int distance(int a, int b){
        int fa = first_appear[a], fb = first_appear[b];
        if(fa>fb) swap(fa,fb);
        auto v = sg.MinElement(0, fa, fb);        
        return (depth[fa] - v.v + depth[fb] - v.v);
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
            int from = par[cur-1];
            while(AB[from].second < r) {
                from = par[from];
            }
            par[cur] = from;
            tree[from].push_back(cur);
        }
    }

    vector<int> index(2*N+3, -1);
    int p = 0;
    auto func = [&](auto func, int cur)->void{
        if( tree[cur].empty() ) {
            for(int i=AB[cur].first; i<=AB[cur].second; i++) {
                index[i] = cur;                
            }
            p = AB[cur].second + 1;
            return;
        }        
        int sz = tree[cur].size();
        for(auto nx: tree[cur]){
            int ns = AB[nx].first;
            for(int i=p; i<ns; i++) {
                index[i] = cur;
            }
            p = ns;
            func(func, nx);           
        }
        int ed = AB[tree[cur][sz-1]].second;
        for(int i=p; i<=AB[cur].second; i++) {
            index[i] = cur;
        }
        p = AB[cur].second + 1;
        
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