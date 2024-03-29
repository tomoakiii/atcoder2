#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000007

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
                tr[i/2].max = max(tr[i].min, tr[i+1].min);
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
        if(tr[ind].l == a && tr[ind].r == b) return tr[ind].min;
        if (tr[ind].c >= a && tr[ind].c < b) return
            min(MaxElement(2*ind+1, a, tr[ind].c),
                MinElement(2*ind+2, tr[ind].c + 1, b));
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


int main () {
    int N, D;
    cin >> N >> D;
    vector<int> A(N);
    for(auto &a:A) cin>>a;
    vector<int> dp(500001, 0);
<<<<<<< HEAD
    SegTree st(dp);
=======
    SegTree<int> st(dp);
>>>>>>> origin/main
    for (int i=0; i<N; i++){
        int l = max(A[i]-D, 0);
        int r = min(A[i]+D, 500000);
        st.SetVal(A[i], 1 + st.MaxElement(0, l, r));
    }
    cout << st.MaxElement(0, 0, 500000) << endl;
    return 0;
}
