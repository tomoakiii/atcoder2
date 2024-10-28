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
        Type val;
    };
    vector<nd> tr;
    // 呼ぶときはgetval(0, index);
    Type getval_main(int ind, int tgt) {
        if (tgt == tr[ind].l && tgt == tr[ind].r) return tr[ind].val;
        tr[2*ind+1].val += tr[ind].val;
        tr[2*ind+2].val += tr[ind].val;
        tr[ind].val = 0;    
        if (tgt <= tr[ind].c) return getval_main(2*ind+1, tgt);
        else                  return getval_main(2*ind+2, tgt);
    }
public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    SegTree(vector<Type> v) {
        sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize);
        for(int i=0; i<sz; i++){
            tr[i+n-1].val = v[i];
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                tr[i/2].val = tr[i].val & tr[i+1].val;
            }
            k*=2;
        }
        for(int i=n-2; i>=0; i--) {      
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;        
        }
    }

    // IsGood(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    Type IsGood(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b) return tr[ind].val;
        if (tr[ind].c >= a && tr[ind].c < b) 
            return IsGood(2*ind+1, a, tr[ind].c) & IsGood(2*ind+2, tr[ind].c + 1, b);
        if (tr[ind].c >= b) return IsGood(2*ind+1, a, b);
        return IsGood(2*ind+2, a, b);
    }

    void SetVal(int ind){
        int i = ind+n-1;
        tr[i].val = !tr[i].val;
        while(i>0){
            i = (i-1)/2;
            tr[i].val = tr[2*i+1].val & tr[2*i+2].val;            
        }
    }
};


int main () {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> s0(N);
    for(int n=0; n<N; n++) s0[n] = S[n]-'0';
    vector<bool> yn(N);
    for(int n=1; n<N; n++) 
    {
        yn[n] = (s0[n] != s0[n-1]);
    }    
    SegTree<bool> st(yn);
    int x, L, R;
    while(Q--){
        cin >> x >> L >> R;
        L--; R--;
        if (x==1){
            if (L > 0) st.SetVal(L);
            if (R+1<N) st.SetVal(R+1);
            
        } else if (x==2) 
        {
            if (L == R){
                cout << "Yes" << endl;
            } else {
                cout << ((st.IsGood(0, L+1, R)) ? "Yes" : "No") << endl;
            }
        }
    }
    return 0;
}
