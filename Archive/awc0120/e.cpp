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
typedef modint998244353 mint2;

template<class Type> class StringHash {
private:
public:
    Type d = 111;
    vector<Type> hash;
    vector<Type> pow;
    vector<Type> rpow;
    int N;
    StringHash(string S="") {
        N = S.size();
        hash.resize(N+1);
        pow.resize(N+1,1);
        rpow.resize(N+1,1);
        Type p = 1;
        rep(i,N) {
            hash[i+1] = hash[i] + p * (S[i]-'A'+1);
            p *= d;
        }
        rep(i,N) {
            pow[i+1] = pow[i] * d;
        }
        rpow[N] = (Type)1/pow[N];
        for(int i=N; i>0; i--) {
            rpow[i-1] = rpow[i] * d;
        }
    }
    Type GetHash(int l, int r){
        r++;
        Type h1 = hash[r] - hash[l];
        return h1 * rpow[l];
    }
    Type GetRawHash(int l, int r){
        r++;
        Type h1 = hash[r] - hash[l];
        return h1;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q; string P;
    cin >> N >> Q >> P;
    ll sz = P.size();
    string rP = P;
    reverse(rP.begin(),rP.end());
    StringHash<mint> SHP(P), SHrP(rP);
    StringHash<mint2> SHP2(P), SHrP2(rP);
    vector<unordered_map<ll,ll>> SH(N);
    vector<unordered_map<ll,ll>> SH2(N);
    
    rep(i,N){
        string S; cin >> S;
        StringHash<mint> SH1(S);
        StringHash<mint2> SH12(S);
        rep(j,S.size()){
            if(j+sz-1>=S.size()) break;
            SH[i][SH1.GetHash(j,j+sz-1).val()]++;
            SH2[i][SH12.GetHash(j,j+sz-1).val()]++;
        }
    }
    while(Q--){
        int i; ll l,r;
        cin >> i >> l >> r;
        i--; l--; r--;
        mint p = SHrP.GetRawHash(sz-1-r,sz-1-l);
        p *= SHP.rpow[sz-1-r] * SHP.pow[l];
        if(l>0) p+= SHP.GetRawHash(0,l-1);
        if(r<sz-1) p+= SHP.GetRawHash(r+1,sz-1);

        mint2 p2;
        p2 = SHrP2.GetRawHash(sz-1-r,sz-1-l);
        p2 *= SHP2.rpow[sz-1-r] * SHP2.pow[l];
        if(l>0) p2+= SHP2.GetRawHash(0,l-1);
        if(r<sz-1) p2+= SHP2.GetRawHash(r+1,sz-1);
        
        ll ans = SH[i][p.val()];
        chmin(ans, SH2[i][p2.val()]);
        cout << ans << "\n";
    }

    return 0;
}