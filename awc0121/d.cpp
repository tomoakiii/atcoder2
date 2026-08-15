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
    val_ind MaxElement(int a, int b){
        return _MaxElement(0, a, b-1);
    }

private:
    val_ind _MaxElement(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b) return tr[ind].max;
        if (tr[ind].c >= a && tr[ind].c < b) return
            max(_MaxElement(2*ind+1, a, tr[ind].c),
                _MaxElement(2*ind+2, tr[ind].c + 1, b));
        if (tr[ind].c >= b) return _MaxElement(2*ind+1, a, b);
        return _MaxElement(2*ind+2, a, b);
    }

public:
    val_ind MinElement(int a, int b){
        return _MinElement(0, a, b-1);
    }
    // MinElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    val_ind _MinElement(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b){
            return tr[ind].min;
        }
        if (tr[ind].c >= a && tr[ind].c < b) {
            return min(_MinElement(2*ind+1, a, tr[ind].c),
                       _MinElement(2*ind+2, tr[ind].c + 1, b));
        }
        if (tr[ind].c >= b) return _MinElement(2*ind+1, a, b);
        return _MinElement(2*ind+2, a, b);
    }

public:
    Type GetVal(int ind){
        int i = ind+n-1;
        return tr[i].val;
    }

public:
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

public:
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

public:
    Type GetSum(int a, int b){
        return _GetSum(0, a, b-1);
    }

private:
    Type _GetSum(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b){
            return tr[ind].val;
        }
        if (tr[ind].c >= a && tr[ind].c < b) {
            return _GetSum(2*ind+1, a, tr[ind].c) +
                _GetSum(2*ind+2, tr[ind].c + 1, b);
        }
        if (tr[ind].c >= b) return _GetSum(2*ind+1, a, b);
        return _GetSum(2*ind+2, a, b);
    }

public:
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,D;
    cin >> N >> D;
    vector<ll> A(N+2,-INF);
    rep(i,N) cin>>A[i+1];
    vector<ll> C(N), cnt(N+2);
    rep(i,N) cin>>C[i];
    SegTree<ll> ST(A);
    rep(i,N){
        auto [mx, j] = ST.MaxElement(0,N+2);
        auto v1 = ST.GetVal(j-1);
        auto v2 = ST.GetVal(j+1);
        if(v1!=-INF){
            ll d=max(0ll, mx-D-v1);
            cnt[j-1]+=d;
            ST.AddVal(j-1,d);
        }
        if(v2!=-INF){
            ll d=max(0ll, mx-D-v2);
            cnt[j+1]+=d;
            ST.AddVal(j+1,d);
        }
        ST.SetVal(j,-INF);
    }
    //rep(i,N+2)cerr<<cnt[i]<<" \n"[i==N+1];
    ll ans=0;
    rep(i,N) ans+=C[i]*cnt[i+1];
    cout<<ans<<endl;
    return 0;
}