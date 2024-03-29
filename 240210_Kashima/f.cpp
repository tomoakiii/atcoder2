#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int N, M;

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
        if (tgt == tr[ind].l && tgt == tr[ind].r){
            Type v = tr[ind].val;
            tr[ind].val = 0;
            return v;
        }
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

    Type getval(int tgt) {
        return getval_main(0, tgt);
    }
    void update() {
        for(int i = 0; i < n-1; i++){
            tr[2*i+1].val += tr[i].val;
            tr[2*i+2].val += tr[i].val;
            tr[i].val = 0;
        }
    }
    void print(){
         for(int i=0; i<sz; i++) cout << tr[i+n-1].val << " ";
         cout << endl; 
    }
};

int main(){
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> keep(N);
    
    for(int i=0; i<N; i++) cin >> A[i];
    LazySegmenttr<ll> tree(A);
    for(int i=0; i<M; i++){
        int b;
        cin >> b;
        ll v = tree.getval(b);
        ll d = v/N;
        ll rem = v%N;
        tree.add(0, 0, N-1, d);
        if (b + rem > N-1) {
            tree.add(0, 0, b+rem-N, 1);
            if (b< N-1){
                tree.add(0, b+1, N-1, 1);
            }
        } else {
            tree.add(0, b+1, b+rem, 1);
        }
    }
    tree.update();
    tree.print();
    return 0;
}

