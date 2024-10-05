#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;


template <class Type> class SegTree {
private:
    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
        map<Type, int> mp;
        nd(){
            mp[0] = 0;
            mp[-1] = 0;
        }
    };
    vector<nd> tr;

public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    SegTree(vector<Type> v) {
        sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize, nd());
        for(int i=0; i<sz; i++) {
            tr[i+n-1].mp.clear();
            tr[i+n-1].mp[v[i]] = 1;
            tr[i+n-1].mp[0] = 0;
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        for(int i=n-2; i>=0; i--) {
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;
            update(i);
        }
    }

    void update(int i){
        vector<pair<Type, int>> v;
        map<Type, int> mp(tr[2*i+1].mp);        
        for(auto m : tr[2*i+2].mp) mp[m.first] += m.second;        
        auto m = mp.rbegin();
        tr[i].mp.clear();
        tr[i].mp[m->first] = m->second;
        m++;
        tr[i].mp[m->first] = m->second;
    }

    void SetVal(int ind, Type val){
        int i = ind+n-1;
        tr[i].mp.clear();
        tr[i].mp[val] = 1;
        tr[i].mp[0] = 0;
        while(i>0){
            i = (i-1)/2;
            update(i);
        }
    }

    Type SecondElement(int indind, int aa, int bb){
        map<Type, int> m;
        auto se = [&](auto se, int ind, int a, int b) -> void{
            if(tr[ind].l == a && tr[ind].r == b){
                for(auto mp: tr[ind].mp) m[mp.first] += mp.second;
                return;
            }
            if (tr[ind].c >= a && tr[ind].c < b) {                
                se(se, 2*ind+1, a, tr[ind].c);
                se(se, 2*ind+2, tr[ind].c + 1, b);
                return;
            }
            if (tr[ind].c >= b) {
                se(se, 2*ind+1, a, b);
                return;
            }
            else {
                se(se, 2*ind+2, a, b);
                return;
            }
        };
        se(se, indind, aa, bb);
        auto mi = m.rbegin();
        mi++;
        return mi->second;
    }
};


int main () {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    SegTree<ll> st(A);
    int q, l, r;
    while(Q--){
        cin >> q >> l >> r;
        if (q==1){
            st.SetVal(l-1, r);
        } else {
            cout << st.SecondElement(0, l-1, r-1) << endl;
        }
    }
    return 0;
}

