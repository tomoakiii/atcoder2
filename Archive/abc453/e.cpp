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
typedef pair<bool,bool> pbb;
int main(){
    ll N;
    cin >> N;
    map<pbb, int>ind;
    ind[{true,true}]=0;
    ind[{true,false}]=1;
    ind[{false,true}]=2;
    ind[{false,false}]=3;
    vector G(N+1, vector<ll>(4));
    rep(i,N) {
        int l,r; cin>>l>>r;
        map<ll, vector<int>> mp; // 0: a-off, 1:a-on, 2: b-off, 3:b-on;
        mp[0].push_back(0);
        mp[l-1].push_back(0);
        mp[l].push_back(1);
        mp[r].push_back(1);
        mp[r+1].push_back(0);

        mp[0].push_back(2);
        mp[N-r-1].push_back(2);
        mp[N-r].push_back(3);
        mp[N-l].push_back(3);
        mp[N-l+1].push_back(2);

        G[0][3]++;

        pbb pre;
        pre={false,false};

        pbb cur;
        cur={false,false};

        for(auto [t,vc]:mp) {
            for(auto v:vc) {
                if(v==0) cur.first=false;
                if(v==1) cur.first=true;
                if(v==2) cur.second=false;
                if(v==3) cur.second=true;
            }
            if(pre != cur) {
                int key = ind[pre];
                G[t][key]--;
                int key2 = ind[cur];
                G[t][key2]++;
            }
            pre=cur;
        }
    }
    rep(i,N-1) {
        rep(k,4) G[i+1][k] += G[i][k];
/*
        cerr<<i+1<<"---";
        rep(k,4) cerr<<G[i+1][k]<<" \n"[k==3];
*/
    }

    Combination<mint> CMB(N);
    mint ans=0;
    for(ll i=1; i<N; i++) {
        ll j=N-i;
        if(G[i][3]>0) continue;
        if(G[i][1]>i) continue;
        if(G[i][2]>j) continue;
        ll rm1 = i-G[i][1];
        ans += CMB.comb(G[i][0], rm1);
    }
    cout<<ans.val()<<endl;
    return 0;
}