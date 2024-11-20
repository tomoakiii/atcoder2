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


/* return x^k % mod */
ll powmod(ll x, ll k, ll mod) {
    if(k==0) return 1%mod;
    ll res = powmod(x, k/2, mod);
    res = (res * res) % mod;
    if(k%2 == 1) res = (res * x) % mod;
    return res;
}


int main(){
    ll N, K;
    cin >> N >> K;
    
    vector<ll> P(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
    }
    vector<ll> Pre = P;
    vector<ll> Nx(N);
    ll cnt = N;
    ll c = 1;
    vector Cycle(N, vector<int>{});
    vector<int> visit(N, false);
    vector<int> ans(N);
    rep(i,N) {
        if(visit[i]) continue;
        int pre = i;
        vector<int> vs{};        
        while(!visit[pre]){
            visit[pre] = true;
            vs.push_back(pre);
            pre = P[pre];
        }
        ll c = vs.size();
        ll p = powmod(2, K, c);
        rep(j,c) {
            ans[vs[j]] = vs[(j+p)%c];
        }
    }
    for(auto a:ans) cout << a+1 << " ";
    cout << endl;
    return 0;
}