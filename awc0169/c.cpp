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

// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template<typename T=int>
struct CC {
    bool initialized;
    vector<T> xs;
    CC(): initialized(false) {}
    void add(T x) { xs.push_back(x);}
    void init() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
        initialized = true;
    }
    int operator()(T x) {
        if (!initialized) init();
        return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
    }
    T operator[](int i) {
        if (!initialized) init();
        return xs[i];
    }
    int size() {
        if (!initialized) init();
        return xs.size();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K,Q;
    cin >> N>>K>>Q;
    vector<ll> A(K),B(K);
    CC<ll>cc;
    int id=0;
    rep(i,K) {
        cin>>A[i]>>B[i];
        A[i],B[i];
        cc.add(A[i]);
        cc.add(B[i]);
    }
    vector<ll> X(Q),P(Q),V(Q);
    rep(i,Q){
        cin>>X[i]>>P[i]>>V[i];
        P[i]--;
        cc.add(V[i]);
    }
    ll M=cc.size();
    rep(q,Q){
        int x=X[q];
        ll p=P[q], v=V[q];
        if(x==1)A[p]=v;
        else B[p]=v;
        auto Am=A;
        auto Bm=B;
        sort(Am.begin(),Am.end());
        sort(Bm.begin(),Bm.end());
        dsu UF(M);
        rep(i,K)if(Am[i]!=Bm[i])UF.merge(cc(Am[i]),cc(Bm[i]));
        vector<int> node(M);
        rep(i,K){
            int li = UF.leader(cc(Am[i]));
            cout << UF.size(li)%2 << " \n"[i==K-1];
        }
    }
    return 0;
}