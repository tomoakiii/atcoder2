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
        vector<Type> val;
        Type sum;
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

        for(int i=0; i<sz; i++){
            tr[i+n-1].val = {v[i]};
            tr[i+n-1].sum = v[i];
        } 
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                tr[i/2].val.reserve(tr[i].val.size() + tr[i+1].val.size());
                tr[i/2].val.insert(tr[i/2].val.end(), tr[i].val.begin(), tr[i].val.end());
                tr[i/2].val.insert(tr[i/2].val.end(), tr[i+1].val.begin(), tr[i+1].val.end());
                sort(tr[i/2].val.begin(), tr[(i-1)/2].val.end());
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

    // MaxElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    long long sum(int ind, int a, int b, Type val){
        if(tr[ind].l == a && tr[ind].r == b){
            
            return tr[ind].sum;
        }
        if (tr[ind].c >= a && tr[ind].c < b){
             return sum(2*ind+1, a, tr[ind].c, val) + sum(2*ind+2, tr[ind].c + 1, b, val);
        }
        if (tr[ind].c >= b){
            return sum(2*ind+1, a, b, val);
        }
        return sum(2*ind+2, a, b, val);   
    }
};


int main () {
    int N, Q;
    cin >> N;
    vector<long long> A(N);
    for(auto &a:A) cin>>a;
    SegTree<long long> st(A);
    cin >> Q;
    long long alpha, beta, gamma, b0=0;
    long long Li, Ri, Xi;
    while(Q--){
        cin >> alpha >> beta >> gamma;
        Li = alpha^b0;
        Ri = beta^b0;
        Xi = gamma^b0;
        if (Li > Ri) return -1;
        b0 = st.sum(0, Li-1, Ri-1, Xi);
        cout << b0 << '\n';
    }
    cout << endl;
    return 0;
}
