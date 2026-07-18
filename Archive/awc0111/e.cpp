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
    ll N;
    cin >> N;
    //vector<StringHash<mint>> S;
    vector<StringHash<mint>> S(N);
    vector<StringHash<mint2>> S2(N);

    rep(i,N) {
        string s; cin>>s;
        //S.push_back(StringHash<mint>(s));
        S[i] = StringHash<mint>(s);
        S2[i] = StringHash<mint2>(s);
    }
    vector<unordered_set<ll>> st(N+1), st2(N+1);
    rep(i,N){
        rep(j, S[i].N-1){
            mint x = S[i].GetHash(0, j);
            st[i].insert(x.val());
            mint2 x2 = S2[i].GetHash(0, j);
            st2[i].insert(x2.val());
        }
    }
    ll ans = 0;
    rep(i,N) {
        bool flg = false;
        for(int j=1; j<S[i].N; j++){
            mint y = S[i].GetHash(j,S[i].N-1);
            mint2 y2 = S2[i].GetHash(j,S[i].N-1);

            if(st[i+1].contains(y.val()) && st2[i+1].contains(y2.val())){
                ans += j;
                flg = true;
                break;
            }
        }
        if(!flg) ans += S[i].N;
    }
    cout << ans << endl;
    return 0;
}