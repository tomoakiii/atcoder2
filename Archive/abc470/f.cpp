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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    dsu UF(N);
    rep(i,M){
        int a,b; cin>>a>>b; a--,b--;
        UF.merge(a,b);
    }
    vector<mint> fact(N+1,1), rfact(N+1, 1);
    for(int i=1;i<=N;i++) fact[i] = fact[i-1] * i;
    rfact[N] = fact[N].inv();
    for(int i=N-1;i>=0;i--) rfact[i] = rfact[i+1] * (i+1);
    ll sz = UF.groups().size();
    mint inv2 = 2;
    inv2 = inv2.inv();
    bool flg =  false;
    mint ans = 1;
    for(auto gg:UF.groups()){
        vector<ll> cnt(30);
        for(auto g:gg){
            char c = S[g];
            int cn = c-'a';
            cnt[cn]++;
        }
        ll p = gg.size();
        mint f = fact[p];
        rep(k,30){
            if(cnt[k] > 1) {
                f *= rfact[cnt[k]];
                flg = true;
            }
        }
        ans *= f;
    }
    if(!flg) ans /= 2;
    cout<<ans.val()<<endl;
    return 0;
}