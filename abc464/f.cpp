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

// nCk = nC(n+n-k)
ll cmb(ll n, ll k){
    if(n-k < k)  k = n-k;
    ll u = 1, l = 1;
    ll st = n, st2 = 1;
    rep(i,k) {
        u *= st;
        st--;
        l *= st2;
        st2++;
    }
    return u/l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,X;
    cin >> N >> X;
    ll N1=N/2;
    ll N2=N-N1;
    vector<ll> A1(N1),A2(N2);
    rep(i,N1) cin>>A1[i];
    rep(i,N2) cin>>A2[i];


    auto get=[&](vector<ll> A, ll N, int x) -> vector< pair<ll,ll> >{
        ll ful=1ll<<N;
        vector<pair<ll,ll>> ret(ful);
        rep(S,ful){
            ll sm=0;
            ll cnt=0;
            if(S>>x && 1) continue;
            rep(i,N){
                if(S>>i & 1) {
                    sm+=A[i];
                    cnt++;
                }
            }
            ret[S]={sm,cnt};
        }
        return ret;
    };

    Combination<mint> CMB(N);
    mint ans=0;

    vector R1(N1+1, vector<pair<ll,ll>>{});
    vector R2(N2+1, vector<pair<ll,ll>>{});
    rep(i,N1+1){
        R1[i] = get(A1,N1,i);
    }
    rep(i,N2+1){
        R2[i] = get(A2,N2,i);
    }

    rep(kkk,2){
        sort(R2[N2].begin(), R2[N2].end());
        vector count(N2+1, vector<ll> (R2[N2].size()));
        rep(j,R2[N2].size()) {
            auto [sm,cnt] = R2[N2][j];
            count[cnt][j+1]++;
        }

        rep(i,N1){
            rep(S,R1[i].size()){
                auto [sm,cnt]=R1[i][S];
                ll sz=R2[N2].size();
                //if(R2[N2][sz-1] + sm + A1[i] < X) continue;
                if(sm>=X) continue;
                pair<ll,ll> key;
                key = {X-sm,0ll};
                auto it = lower_bound(R2[N2].begin(), R2[N2].end(), key) - R2[N2].begin();
                it--; // upper
                key = {X-sm-A1[i],0ll};
                auto it2 = lower_bound(R2[N2].begin(), R2[N2].end(), key) - R2[N2].begin(); // lower
                for(int i=1;i<=N2;i++) {
                    ll p = count[i][it+1]-count[i][it2]; // pattern num
                    ll cnt2=cnt+i;
                    ans += CMB.fct[cnt2] * CMB.fct[N-cnt2] * p * CMB.rfct[cnt2+1];
                }
            }
        }
        swap(A1,A2);
        swap(N1,N2);
        swap(R1,R2);
    }
    cout<<ans.val()<<endl;
    return 0;
}