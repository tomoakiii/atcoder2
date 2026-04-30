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
typedef modint998244353 mint;
template <class Type> class Combination{
public:
    vector<mint> fct{}; // array of factorial. fct[k] = k!
    vector<mint> rfct{}; // rmfct[k] = 1/k!
    Combination(int M){
        fct.resize(M+1, 1);
        rfct.resize(M+1, 1);
        for(ll i=2; i<=M; i++) {
            mint ip = i;
            fct[i] = fct[i-1] * ip;
        }
        rfct[M] = 1/fct[M];
        for(ll i=M; i>1; i--) {
            mint ip = i;
            rfct[i-1] = rfct[i] * ip;
        }
    }

    // kCr = (k!)/(r!)/((k-r)!)
    mint comb(ll n, ll k){
        if (n < k || k < 0) return 0;
        return fct[n] * rfct[k] * rfct[n-k];
    };

};
int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<mint> S(N+1);
    rep(i,N) S[i+1]=S[i]+A[i];
    vector<mint> ssm(K+1,0);
    vector<mint> psr(K+1,1);
    ssm[0]=1;
    Combination<mint> CMB(K);
    mint ans = 0;
    for(int r=1;r<=N;r++) {
        vector<mint> sr(K+1,1);
        vector<mint> nsr(K+1,1);
        mint sm = 0;
        for(int k=0;k<=K;k++){
            if(k>0) sr[k]=sr[k-1]*S[r];
            if(k>0) nsr[k]=nsr[k-1]*(-S[r]);
        }
        for(int k=0;k<=K;k++){
            sm += CMB.comb(K,k) * sr[k] * ssm[K-k];
        }
        for(int k=0;k<=K;k++){
            ssm[k] = ssm[k] + nsr[k];
        }
        ans += sm;
    }
    cout<<ans.val()<<endl;
    return 0;
}