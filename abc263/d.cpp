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

template <class Type> class SegTree {
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
        Type val;
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

    void SetVal(int ind, Type val){
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

    void AddVal(int ind, Type delta){
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
};

int main(){
    ll N, L, R;
    cin >> N >> L >> R;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> S(N+1);
    rep(i,N) S[i+1] = S[i] + A[i];
    vector<ll> S2(N+1);
    ll tL = 0;
    rep(i,N) {
        S2[i] = tL - S[i];
        tL += L;
    }
    SegTree<ll> ST(S2);
    ll tS = 0;
    ll k = 0;
    auto lv = ST.MinElement(0, 0, N);
    ll lh = lv.v + S[N];
    ll ans = lh;
    for(int i=N-1; i>=0; i--){
        tS += A[i];
        k++;
        ll rh = min(tS, k*R);
        auto lv = ST.MinElement(0, 0, i);
        ll lh = lv.v + S[i];
        chmin(ans, rh + lh);
    }
    cout << ans << endl;
    return 0;
}