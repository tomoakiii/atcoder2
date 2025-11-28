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

typedef modint1000000007 mint;

map<ll, int> prime_factorization(ll K){
    map<ll, int> mp;
    ll k = K;
    ll i=2;
    while(true){
        while(k%i == 0) {
            mp[i]++;
            k /= i;
        }
        if(i*i > K) break; // break here. for(; i*i<=K ;) is NG
        i++;
    }
    if (k!=1) mp[k]++; // don't forget to add the last piece (10=2x5)
    return mp;
}

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
    ll N,M;
    cin >> N >> M;
    auto mp = prime_factorization(M);
    Combination<mint> CMB(N*20);
    mint ans = 1;
    mint div = 1;
    for(auto [v,c]: mp) {
        ans *= CMB.fct[c + N - 1];
        div *= CMB.fct[c];
        div *= CMB.fct[N-1];
    }
    ans = ans / div;
    cout << ans.val() << endl;
    return 0;
}