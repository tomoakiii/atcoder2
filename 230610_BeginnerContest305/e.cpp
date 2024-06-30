#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

template <class Type> class SegTree {
private:
    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
        pair<Type, int> min;
        pair<Type, int> max;
        pair<Type, int> val;
    };
    vector<nd> tr;
public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    SegTree(vector<Type> v) {
        sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize);
        for(int i=0; i<sz; i++) {
            tr[i+n-1].val = make_pair(v[i], i);
            tr[i+n-1].max = make_pair(v[i], i);
            tr[i+n-1].min = make_pair(v[i], i);
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                tr[i/2].min = min(tr[i].min, tr[i+1].min);
                tr[i/2].max = max(tr[i].max, tr[i+1].max);
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
    pair<Type, ll> MaxElement(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b) return tr[ind].max;
        if (tr[ind].c >= a && tr[ind].c < b) return
            max(MaxElement(2*ind+1, a, tr[ind].c),
                MaxElement(2*ind+2, tr[ind].c + 1, b));
        if (tr[ind].c >= b) return MaxElement(2*ind+1, a, b);
        return MaxElement(2*ind+2, a, b);   
    }

    // MinElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    pair<Type, ll> MinElement(int ind, int a, int b){
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

    void SetVal(int ind, Type val){
        int i = ind+n-1;
        tr[i].val = tr[i].min = tr[i].max = make_pair(val, ind);
        while(i>0){
            int ii = (i-1)/2;
            tr[ii].min = min(tr[ii*2+1].min, tr[ii*2+2].min);
            tr[ii].max = max(tr[ii*2+1].max, tr[ii*2+2].max);
            i = ii;
        }
    }

    pair<Type, ll> GetVal(int ind){
        int i = ind+n-1;        
        return tr[i].val;
    }
};

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector A(N, vector<ll>{});
    ll a, b;
    rep(i, M) {
        cin >> a >> b;
        a--; b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    vector<ll> X(N, -1);
    ll p, h;
    set<ll> st;
    rep(i, K) {
        cin >> p >> h;
        p--;
        X[p] = h;
        st.insert(p);
    }
    SegTree<ll> seg(X);
    vector<bool> visit(N, false);
    while(true){
        auto s = seg.MaxElement(0, 0, N);
        if (s.first == 0) {
            break;
        }
        seg.SetVal(s.second, -1);
        visit[s.second] = true;       
        for(auto nx : A[s.second]){            
            if (!visit[nx]){
                auto v = seg.GetVal(nx);
                seg.SetVal(nx, max(s.first-1, v.first));
                visit[nx] = true;
                if (s.first >= 1) st.insert(nx);
                
            }
        }
    }
    cout << st.size() << endl;
    for(auto a: st) {
        cout << (a+1) << " ";
    }
    cout << endl;
    return 0;
}