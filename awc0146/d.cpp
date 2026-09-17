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
    Type d = 1111111;
    vector<Type> hash;
    vector<Type> pow;
    vector<Type> rpow;
public:
    int N;
    StringHash(string S="") {
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
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<StringHash> SH(N);
    vector<string> S(N);
    vector has(N, vector<ll>(M));
    rep(i,N){
        string s,c; cin>>s>>c;
        s= s+s; c=c+c;
        rep(j,2*M){
            if(c[j]=='1')s[j]='?';
        }
        StringHash<mint> sh(s);
        SH[i] = StringHash<mint>(sh);
        rep(j,M) {
            has[i][j] = sh.GetHash(j,j+M-1);
        }
        S[i] = s;
    }

    return 0;
}