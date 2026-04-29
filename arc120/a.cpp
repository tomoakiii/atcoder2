#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;
typedef modint998244353 mint;

template<class Type> class StringHash {
private:
    Type d = 'z'-'a'+1;
    vector<Type> hash;
    vector<Type> pow;
    vector<Type> rpow;
    int N;
public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    StringHash(string S) {
        N = S.size();
        hash.resize(N+1);
        pow.resize(N+1,1);
        rpow.resize(N+1,1);
        Type p = 1;
        rep(i,N) {
            hash[i+1] = hash[i] + p * (S[i]-'a');
            p *= d;
        }
        rep(i,N) {
            pow[i+1] = pow[i] * d;
        }
        rpow[N] = (mint)1/pow[N];
        for(int i=N; i>0; i--) {
            rpow[i-1] = rpow[i] * d;
        }
    }
    Type GetHash(int l, int r){
        r++;
        Type h1 = hash[r] - hash[l];
        return h1 * rpow[l];
    }
};

int main(){
    string S; cin>>S;
    ll last=-1;
    StringHash<mint> ST(S);
    int l=0;
    ll ans=0;
    rep(r,S.size()) {
        mint h = ST.GetHash(l, r);
        if(h.val() == last) {
            continue;
        } else {
            ans++;
            last = h.val();
            l=r+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}