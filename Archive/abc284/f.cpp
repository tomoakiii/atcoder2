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

    Type getPow(int k){
        return pow[k];
    }
};

int main(){
    ll N;
    cin >> N;
    string T;
    cin >> T;
    string T2 = T;
    reverse(T2.begin(),T2.end());
    StringHash<mint> t1(T);
    StringHash<mint> t2(T2);
    int str = N;
    for(int l=0; l<=N; l++) {
        mint lh = t1.GetHash(0,l-1);
        mint rh = t1.GetHash(l+N, 2*N-1);
        mint hs = rh * t1.getPow(l) + lh;
        mint hs2 = t2.GetHash(str, str+N-1);
        str--;
        if(hs.val() == hs2.val()) {
            string ans = T.substr(l, N);
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
            cout<<l<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}