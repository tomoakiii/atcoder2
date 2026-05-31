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

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N);
    rep(i,N) cin>>A[i]>>B[i];
    fenwick_tree<ll> fA(N), fB(N);
    rep(i,N) {
        fA.add(i, A[i]);
        fB.add(i, B[i]);
    }
    while(Q--){
        int query;
        cin >> query;
        if(query == 1){
            int i;
            ll a,b;
            cin >> i >> a >> b;
            i--;
            fA.add(i, -A[i]);
            fB.add(i, -B[i]);
            fA.add(i, a);
            fB.add(i, b);
            A[i]=a;
            B[i]=b;
        } else {
            ll d; cin>>d;
            ll Asm=fA.sum(0, N), Bsm=fB.sum(0, N);
            __uint128_t Asm128=Asm, Bsm128=Bsm, d128=d;
            ll bb = 0, aa = d;
            bool flg=true;
            rep(i,N){
                aa += A[i];
                bb += B[i];
                if(bb >= aa) {
                    cout<<i+1<<endl;
                    flg=false;
                    break;
                }
            }
            if(!flg) continue;
            if(Asm >= Bsm) {
                cout<<-1<<endl;
            }else{
                __uint128_t l=0, r=1e16;
                while(r-l>1){
                    __uint128_t m=(l+r)/2;
                    __uint128_t p = m/N;
                    __uint128_t q = m%N;
                    __uint128_t As = p*Asm128 + fA.sum(0, q);
                    __uint128_t Bs = p*Bsm128 + fB.sum(0, q);
                    if(Bs - As >= d128) r=m;
                    else l=m;
                }
                ll ans=r;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}