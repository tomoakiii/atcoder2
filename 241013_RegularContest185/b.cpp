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
    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
        pair<Type, int> min;
        pair<Type, int> max;
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
        for(int i=0; i<sz; i++) tr[i+n-1].val = v[i];
        for(int i=0; i<sz; i++) tr[i+n-1].max = tr[i+n-1].min = {v[i], i};
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
    pair<Type, int> MaxElement(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b) return tr[ind].max;
        if (tr[ind].c >= a && tr[ind].c < b) return
            max(MaxElement(2*ind+1, a, tr[ind].c),
                MaxElement(2*ind+2, tr[ind].c + 1, b));
        if (tr[ind].c >= b) return MaxElement(2*ind+1, a, b);
        return MaxElement(2*ind+2, a, b);   
    }

    // MinElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    pair<Type, int> MinElement(int ind, int a, int b){
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
        tr[i].val = val;
        tr[i].min = tr[i].max = {val, i};
        while(i>0){
            int ii = (i-1)/2;
            tr[ii].min = min(tr[ii*2+1].min, tr[ii*2+2].min);
            tr[ii].max = max(tr[ii*2+1].max, tr[ii*2+2].max);
            i = ii;
        }
    }

    Type GetVal(int ind){
        int i = ind+n-1;
        return tr[i].val;
    }
};

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> A(N, 0);
        rep(i,N) cin>>A[i];
        SegTree tree(A);
        ll last = A[0];
        bool flg2 = true;
        for(int i=1; i<N; i++){
            ll cur = tree.GetVal(i);
            if (cur >= last) {                
                continue;
            }
            bool flg = true;
            while(true){
                ll d = cur - last;
                auto [v, ind] = tree.MaxElement(0, i, N-1);
                if (v <= d) {
                    flg = false;
                    break;
                }
                if (v-d >= cur + d) {
                    tree.SetVal(i, cur+d);
                    tree.SetVal(ind, v-d);
                    break;
                }
                else {
                    ll x = (v-cur) / 2;
                    tree.SetVal(i, cur+x);
                    tree.SetVal(ind, v-x);
                }
                cur = tree.GetVal(i);
            }
            last = tree.GetVal(i);
            if (!flg) {
                cout << "No" << endl;
                flg2 = false;
                break;
            }
        }
        if(flg2) {
            cout << "Yes" << endl;
        }
    
    }
    return 0;
}