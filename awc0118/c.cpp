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
    ll N,M;
    cin >> N >> M;
    string S; cin>>S;
    StringHash<mint> SH(S);
    StringHash<mint> ST("ATCODER");
    mint th = ST.GetHash(0,6);
    deque<bool> A;
    rep(i,N-6){
        if(SH.GetHash(i,i+6).val() == th.val()){
            A.push_back(true);
        } else {
            if(A.empty()) {
                A.push_back(false);
            } else if (*A.back() == true){
                A.push_back(false);
            } else {
                continue;
            }
        }
    }
    ll ans=0;
    ll sz=A.size();
    vector<int> B;
    ll cnt=0;
    rep(i,sz){
        if(A[i]){
            cnt++;
        } else {
            B.push_back(cnt);
            cnt=0;
        }
    }

    cout<<ans<<endl;
    return 0;
}