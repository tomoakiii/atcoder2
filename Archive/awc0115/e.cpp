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
template<class Type> class StringHash {
private:
    Type d = 31;
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
            hash[i+1] = hash[i] + p * (S[i]-'a'+1);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S,T; cin>>S>>T;
    ll N,M; N=S.size(); M=T.size();
    string S2 = S;
    int it=0;
    while(S2.size() <= N+M) {
        S2.push_back(S[it]);
        it++;
        it%=N;
    }
    StringHash<mint> SH(S2);
    StringHash<mint> TH(T);
    mint h = TH.GetHash(0,M-1);
    ll ans=0;
    rep(i,N){
        mint h1 = SH.GetHash(i, i+M-1);
        ans+=(h.val() == h1.val());
    }
    cout<<ans<<endl;
    return 0;
}