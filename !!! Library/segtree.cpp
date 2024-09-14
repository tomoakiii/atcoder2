#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

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
            int ii = (i-1)/2;
            tr[ii].min = min(tr[ii*2+1].min, tr[ii*2+2].min);
            tr[ii].max = max(tr[ii*2+1].max, tr[ii*2+2].max);
            i = ii;
        }
    }
};


// test case:
// 10 5
// 10 1 6 8 7 2 5 9 3 4

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N), OD(N);        
    for(int i=0; i<N;i++) {
        cin >> P[i];
        P[i]--;
        OD[P[i]] = i;        
    }
    SegTree<ll> ST(OD);
    ll sm = INF;
    for(int i=0; i<N-K+1; i++){
        ll end = i+K-1;
        ll mn = ST.MinElement(0, i, end);
        ll mx = ST.MaxElement(0, i, end);
        sm = min(sm, mx - mn);
    }
    
    cout << sm << endl;
    return 0;
}