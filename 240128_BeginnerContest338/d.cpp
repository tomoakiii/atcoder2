#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000007;

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
public:
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
        for(int i = 1; i < 2*n-1; i++){
            tr[i].val += tr[i/2].val;
        }
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
    int N, M;
    cin >> N >> M;
    LazySegmenttr<int> seg( vector<int>(N, 0) );// freq[0]=0->1, freq[N-1]=N-1 -> 0

    vector<int> X(N);
    for (int i=0;i<M;i++) {
        cin >> X[i];
        X[i]--;
    }
    int last = X[0];
    
    for (int i=1;i<M;i++) {
        int s=X[i-1], g=X[i];
        if (s>g) swap(s,g);
        if (g-s <= N/2){
            seg.add(0, s, g-1, 1);
        }
        else{
            seg.add(0, g, N-1, 1);
            if (s>0) seg.add(0, 0, s-1, 1);
        }
    }
    seg.update();
    int mb = seg.getmin();
    auto X2 = X;
    for (int i=0; i<M; i++){
        X2[i] = (X[i]-mb-1+N)%N;
    }
    LazySegmenttr<int> seg2(vector<int>(N, 0) );
    for (int i=1;i<M;i++) {
        int s=X2[i-1], g=X2[i];
        if (s>g) swap(s,g);
         seg2.add(0, s, g-1, 1);
    }
    seg2.update();

    cout << seg2.getsum() << endl;
    return 0;
}

