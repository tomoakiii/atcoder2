#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class Type> class SegTree {
private:
    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
        vector<pair<Type, int>> mp;
        Type val = 1;
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
            tr[i+n-1].val = v[i];
        }
        for(int i=n-1; i<trsize; i++) {
            tr[i].mp.resize(2);
            tr[i].mp[0] = {tr[i].val, 1};
            if (tr[i].mp[0] > tr[i].mp[1]) swap(tr[i].mp[0], tr[i].mp[1]);
        }

        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        for(int i=n-2; i>=0; i--) {      
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;
            update(i);
        }
    }

    void update(int ind){
        vector<pair<Type, int>> v;
        v.insert(v.begin(), tr[2*ind+1].mp.begin(), tr[2*ind+1].mp.end());
        v.insert(v.begin()+2, tr[2*ind+2].mp.begin(), tr[2*ind+2].mp.end());
        sort(v.begin(), v.end());
        for (int i = 0; i < 3; i++){
            if (v[i].first == v[i+1].first){
                v[i].second += v[i+1].second;
                v[i+1].first += 10;
            }
        }
        sort(v.begin(), v.end());
        v.pop_back(); v.pop_back();            
        tr[ind].mp = v;
    }

    // MaxElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    vector<pair<Type, int>> GetMp(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b) {
            return tr[ind].mp;
        }
        if (tr[ind].c >= a && tr[ind].c < b){
            vector<pair<Type, int>> v;
            auto v1 = GetMp(2*ind+1, a, tr[ind].c);
            v.insert(v.begin(), v1.begin(), v1.end());
            auto v2 = GetMp(2*ind+2, tr[ind].c + 1, b);
            v.insert(v.begin()+2, v2.begin(), v2.end());
            sort(v.begin(), v.end());
            for (int i = 0; i < 3; i++){
                if (v[i].first == v[i+1].first){
                    v[i].second += v[i+1].second;
                    v[i+1].first += 10;
                }
            }
            sort(v.begin(), v.end());
            v.pop_back();
            v.pop_back();
            return v;
        }
        if (tr[ind].c >= b) return GetMp(2*ind+1, a, b);
        return GetMp(2*ind+2, a, b);
    }

    void SetVal(int ind, Type val){
        int i = ind+n-1;
        tr[i].val = val;
        tr[i].mp[0].first = val;
        while(i>0){
            i = (i-1)/2;
            update(i);
        }
    }
};


int main () {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(auto &a:A) {
        int b;
        cin >> b;
        a = -1 * b;
    }
    SegTree<ll> st(A);
    int q, l, r;
    while(Q--){
        cin >> q >> l >> r;
        if (q==1){
            st.SetVal(l-1, -1 * r);
        } else {
            auto m = st.GetMp(0, l-1, r-1);
            cout << m[1].second << endl;
        }
    }
    return 0;
}

