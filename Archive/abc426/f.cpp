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

using S = pair<ll,int>;
using F = ll;

S op(S a, S b){ return std::min(a, b); }
S e(){ return {INF, -1}; }
S mapping(F f, S x){    
    x.first += f;    
    return x;
}
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int op2(int a, int b) {return a+b;}
int e2(){return 0;}

int main(){
    int N; cin>>N;
    vector<S> A(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second = i;
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);
    segtree<int, op2, e2> EmptySeg(vector<int>(N,1));
    int Q; cin>>Q;
    rep(q,Q) {
        int l, r; ll k;
        cin>>l>>r>>k;
        l--; r;
        LS.apply(l,r,-k);
        ll ans = k * EmptySeg.prod(l, r);
        while(true){
            auto [x, id] = LS.prod(l, r);
            if(x < 0) {
                EmptySeg.set(id, 0);
                LS.apply(id, id+1, INF);
                ans += x;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }    
    return 0;
}