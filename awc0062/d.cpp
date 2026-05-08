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
    ll N;
    string S;
    cin >> N >> S;
    vector<unordered_map<ll,ll>> st(N+1);
    rep(i,N) {
        mint sm=0;
        int cnt=0;
        for(int j=i; j<N; j++){
            sm = sm*10 + (S[j]-'0');
            cnt++;
            st[cnt][sm.val()]++;
        }
    }
    vector<mint> p(N,1);
    rep(i,N-1)p[i+1]=p[i]*10;
    ll ans=0;
    for(int i=1; i<N; i++){
        for(auto [s,c]:st[i]) {
            rep(k,i){
                mint tgt = s + p[k];
                if(st[i].contains(tgt.val())){
                    cerr<<s<<" "<<tgt.val()<<endl;
                    ans+=c*st[i][tgt.val()];
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}