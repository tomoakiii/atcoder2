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
        Type min;
        Type max;
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
        for(int i=0; i<sz; i++) tr[i+n-1].val = tr[i+n-1].max = tr[i+n-1].min = v[i];
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
    Type MaxElement(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b) return tr[ind].max;
        if (tr[ind].c >= a && tr[ind].c < b) return
            max(MaxElement(2*ind+1, a, tr[ind].c),
                MaxElement(2*ind+2, tr[ind].c + 1, b));
        if (tr[ind].c >= b) return MaxElement(2*ind+1, a, b);
        return MaxElement(2*ind+2, a, b);   
    }

    // MinElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    Type MinElement(int ind, int a, int b){
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
        tr[i].val = tr[i].min = tr[i].max = val;
        while(i>0){
            tr[(i-1)/2].min = min(tr[(i-1)/2].min, tr[i].min);
            tr[(i-1)/2].max = max(tr[(i-1)/2].max, tr[i].max);
            i = (i-1)/2;
        }
    }
};


int main(){
    ll N, C;
    cin >> N >> C;
    vector<ll> A(N, 0);
    ll sm = 0;
    rep(i, N) {
        cin >> A[i];
        sm += A[i];
    }
    bool flg = C>0;
    if (!flg){
        rep(i, N) {
            A[i] *= -1;
        }
        sm *= -1;
    }
    A.insert(A.begin(), 0);
    A.push_back(0);
    N+=2;
    rep(i, N-1) {
        A[i+1] += A[i];
    }
    SegTree<ll> seg(A);
    ll ans = 0;
    for(int i=N-1; i>=1; i--){
        ll t = A[i-1];
        ll m = seg.MinElement(0, 0, i-1);
        ans = max(ans, t-m);
    }
    
    if (flg){
        if (ans > 0) sm += (C-1)*ans;
    } else {
        if (ans >= 0) sm += (C-1)*ans;
        sm *= -1;
    }
    
    cout << sm << endl;
    return 0;
}