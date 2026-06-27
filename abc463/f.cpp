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

template <class Type> class PowMod {
private:
    ll MMax = 100; // 2^100 = 1.2E30 までのダブリング
    vector<Type> PM;
public:
    // p^x
    PowMod(ll p) {
        PM.resize(MMax);
        PM[0] = 1;
        PM[1] = p;
        for(ll i=1; i<MMax-1; i++) {
            PM[i+1] = PM[i]*PM[i];
        }
    }

    // p^x
    Type GetPow(ll x) {
        Type ret = 1;
        int id = 1;
        while(x) {
            if(x%2 == 1) {
                ret *= PM[id];
            }
            id++;
            x /= 2;
        }
        return ret;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll mx=0;
    vector<pair<ll,ll>> v(N);
    rep(i,N){
        cin>>v[i].first>>v[i].second;
        chmax(mx, v[i].first);
        chmax(mx, v[i].second);
    }
    Combination<mint> CMB(2*N);
    vector<ll> type(N);
    vector<ll> cnt(5);
    rep(i,N){
        auto [a,b] = v[i];
        if(b>a) swap(a,b);
        if(a<mx-1){
            type[i]=t;
            continue;
        }
        if(a==mx-1){
            if(b==mx-1) {
                type[i]=3;
                cnt[3]++;
            }else{
                type[i]=4;
                cnt[4]++;
            }
        } else {
            if(b==mx){
                type[i]=0;
                cnt[0]++;
            }else if(b==mx-1){
                type[i]=1;
                cnt[1]++;
            }else {
                type[i]=2;
                cnt[2]++;
            }
        }
    }
    vector<mint> num(2);
    mint d2 = 1;
    d2 /= 2;
    PowMod<mint> PM(d2);
    vector<pair<mint,mint>> ans(5);
    if(cnt[0] == 0) {
        {
            // win--5
            // case-a: win #1 and #2
            ll sm = (cnt[1]+cnt[2]-1);
            mint p = 0;
            mint d = PM.GetPow(sm);
            rep(i, sm+1){
                mint c = CMB.comb(sm, i);
                c *= i;
                p += c;
            }
            p*=d; // num exp
            mint ex = d2 / (p+1);
            ans[1].first += ex;
            ans[2].first += ex;
        }
        {
            // win--4
            // all #1 and #2 loose
            ll sm = cnt[1] + cnt[2] - 1;
            mint q = PM.GetPow(sm); // all loose pos
            mint p = q * (cnt[1] + cnt[1] + cnt[2] - 2);
            mint ex = d2 / (p+1);
            ans[1].second += ex;
            ans[1].first += ex;
            ans[2].first += ex;
            ans[3].first += ex;
            ans[3].second += ex;
        }

    }
    return 0;
}