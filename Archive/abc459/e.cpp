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
    ll N;
    cin >> N;
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int p; cin>>p; p--;
        uv[p].push_back(i+1);
    }
    struct node{
        ll nyet;
        ll ball;
    };
    Combination<mint> CMB(1e6);
    vector<node> V(N);
    rep(i,N){
        ll c; cin>>c; V[i].ball=c;
    }
    vector<ll> D(N);
    rep(i,N)cin>>D[i];
    //bool flg=true;
    mint ans=1;
    mint a=1,b=1;
    auto dfs1=[&](auto dfs1, int cur, int pre=-1)->void{
        for(auto nx:uv[cur]){
            if(nx==pre)continue;
            dfs1(dfs1, nx, cur);
            V[cur].ball += V[nx].ball;
        }
        /*
        if(V[cur].ball < D[cur]) {
            flg=false;
            return;
        }
        if(V[cur].ball<1e6) {
            ans*=CMB.comb(V[cur].ball, D[cur]);
        } else{
        }
        */

        ll st=V[cur].ball;
        ll btm=1;
        rep(i, D[cur]){
            a*=st;
            st--;
            b*=btm; btm++;
        }

        V[cur].ball -= D[cur];
    };
    dfs1(dfs1, 0, -1);
    ans = (a/b);
    cout<<ans.val()<<endl;
    return 0;
}