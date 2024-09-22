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
template <class Type> class LazySegmenttr {
private:
    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
        Type val;
        int layer;
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
    LazySegmenttr(vector<Type> v) {
        sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize);

        for(int i=0; i<sz; i++)  tr[i+n-1].val = v[i];
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        for(int i=n-2; i>=0; i--) {      
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;            
        }
    }
    
    // 呼ぶときはadd(0, start, goal, val);
    void add(int ind, int a, int b, Type val){
        if(ind > trsize){
             return;
        }
        if(tr[ind].l == a && tr[ind].r == b){
            tr[ind].val += val;
//            cout << tr[ind].l << "~" << tr[ind].r << endl;
        } else if (tr[ind].c >= a && tr[ind].c < b) {
            add(2*ind+1, a, tr[ind].c, val);
            add(2*ind+2, tr[ind].c + 1, b, val);
        } else if (tr[ind].c >= b) {
            add(2*ind+1, a, b, val);
        } else if (tr[ind].c < b) {
            add(2*ind+2, a, b, val);
        }
    }

    void update() {
        for(int i = 0; i < n-1; i++){
            tr[2*i+1].val += tr[i].val;
            tr[2*i+2].val += tr[i].val;
            tr[i].val = 0;
        }
    }

    Type getval(int tgt) {
        return getval_main(0, tgt);
    }

    Type getmin() {
        Type minv = INF;
        int mind;
        for(int i = n-1; i < n-1+sz; i++){
            if(minv > tr[i].val){
                minv = tr[i].val;
                mind = i;
            }
        }
        return mind - (n-1);
    }

    Type getsum() {
        Type sumv = 0;
        for(int i = n-1; i < n-1+sz; i++) sumv += tr[i].val; 
        return sumv;
    }
};

int main(){
    ll N;
    cin >> N;
    vector<ll> H(N+1, INF);
    rep(i,N) cin>>H[i+1];
    vector<ll> next(N+1, 0);
    next[0] = -1;
    vector<ll> ans(N);
    for(int i=1; i<N+1; i++) {
        int k = i-1;
        while(k != -1) {
            if(H[k] > H[i]) {
                next[i] = k;
                break;
            } else {                
                k = next[k];                
            }
        }
    }

    LazySegmenttr<int> seg( vector<int>(N+1, 0));
    for(int i=2; i<=N; i++) {        
        seg.add(0, next[i], i-1, 1);
    }

    for(int i=1; i<=N; i++) {
        int p = seg.getval(i);
        cout << p << " ";   
    }        
    
    cout << endl;
    return 0;
}