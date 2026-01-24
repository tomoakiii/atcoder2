// https://atcoder.jp/contests/abc221/tasks/abc221_e

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

    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
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
            tr[i+n-1].val = v[i];
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
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


    void AddVal(int ind, Type delta){
        int i = ind+n-1;
        tr[i].val = tr[i].val + delta;
        while(i>0){
            int ii = (i-1)/2;
            tr[ii].val = tr[ii*2+1].val + tr[ii*2+2].val;
            i = ii;
        }
    }


    void SetVal(int ind, Type val){
        int i = ind+n-1;
        tr[i].val = val;
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

};
typedef modint998244353 mint;
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    set<ll> st;
    int ind=-1;
    rep(i,N) {
        cin>>A[i];
        st.insert(A[i]);
    }
    unordered_map<ll,int> mp;
    for(auto s: st) {
        ind++;
        mp[s] = ind;
    }
    const int M = st.size();
    rep(i,N) A[i] = mp[A[i]];


    vector<mint> p2(N,1);
    rep(i,N-1) p2[i+1] = 2*p2[i];
    vector<mint> indp2(N,1/p2[N-1]);
    for(int i=N-2; i>=0; i--) indp2[i] = 2*indp2[i+1];

    SegTree<mint> ST(vector<mint>(M+1));
    ST.AddVal(A[0], p2[N-1]);
    mint sm = 0;
    for(int i=1; i<N; i++) {
        mint p = ST.GetSum(0,0,A[i]);
        p *= indp2[N-i];
        ST.AddVal(A[i], p2[N-1-i]);
        sm += p;
    }
    cout<<sm.val()<<endl;
    return 0;
}