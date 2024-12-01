#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

template <class Type> class LazySegmenttr {
private:
    struct val_ind{
        Type v;
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
        Type sum, lazy_app = INF, lazy_sum = INF;
    };

    vector<nd> tr;

public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    LazySegmenttr(vector<Type> v) {
        sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize);
        for(int i=0; i<sz; i++) {
            tr[i+n-1].sum = tr[i+n-1].max.v = tr[i+n-1].min.v = v[i];
            tr[i+n-1].max.i = tr[i+n-1].min.i = i;
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                tr[i/2].max = max(tr[i].max, tr[i+1].max);
                tr[i/2].min = min(tr[i].min, tr[i+1].min);
                tr[i/2].sum = tr[i].sum + tr[i+1].sum;
            }
            k*=2;
        }
        for(int i=n-2; i>=0; i--) {      
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;        
        }
    }
    
    // 呼ぶときはadd(0, start, goal, val);
    void add(int ind, int a, int b, Type val){
        if(ind > trsize){
             return;
        }
        if(tr[ind].l == a && tr[ind].r == b){
            if(tr[ind].lazy_sum == INF) tr[ind].lazy_sum = val;
            else tr[ind].lazy_sum += val;
            tr[ind].sum += (b-a+1)*val;
            chmax(tr[ind].max.v, tr[ind].max.v + val);
            chmin(tr[ind].min.v, tr[ind].min.v + val);
            int i = ind;
            if(i%2 == 0) i--;
            while(i) {
                tr[i/2].max = max(tr[i].max, tr[i+1].max);
                tr[i/2].min = min(tr[i].min, tr[i+1].min);
                tr[i/2].sum = tr[i].sum + tr[i+1].sum;
                i /= 2;
            }
        } else if (tr[ind].c >= a && tr[ind].c < b) {
            add(2*ind+1, a, tr[ind].c, val);
            add(2*ind+2, tr[ind].c + 1, b, val);
        } else if (tr[ind].c >= b) {
            add(2*ind+1, a, b, val);
        } else if (tr[ind].c < b) {
            add(2*ind+2, a, b, val);
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

    Type GetSum(int ind, int a, int b){
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

    void DispMaxTree() {
        int ind = 0;
        int nx = 1;
        while(ind < trsize) {
            for(int i=0; i < nx; i++) {
                cout << ind << "(" << tr[ind].l << "-" << tr[ind].r << "):" << tr[ind].max.v << ", ";
                ind++;
            }
            cout << endl;
            nx *= 2;
        }
        cout << endl;
    }

};

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll H, W, N;
    cin >> H >> W >> N;
    vector<ll> R(N), C(N), L(N);
    vector<pair<ll, int>> vp{};
    rep(i,N) {
        cin>>R[i]>>C[i]>>L[i];
        R[i]--, C[i]--;
        vp.push_back({R[i], i});
    }
    sort(vp.rbegin(), vp.rend());
    vector<ll> col(W);
    LazySegmenttr<ll> LS(col);
    vector<ll> ans(N);
    
    for(auto m: vp){
        int p = m.second;
        auto [mx, k] = LS.MaxElement(0, C[p], C[p] + L[p] - 1);
        LS.add(0, C[p], C[p] + L[p] - 1, 1);
        ans[p] = H - mx;
        LS.DispMaxTree();
    }
    rep(i, N) cout << ans[i] << endl;
    return 0;
}