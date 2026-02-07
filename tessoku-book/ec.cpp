// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bd
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
typedef pair<ll, pair<int,int>> pl;
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
    ll N,Q;
    string S;
    cin>>N>>Q>>S;
    StringHash<mint> SH(S);
    reverse(S.begin(),S.end());
    StringHash<mint> SH2(S);

    while(Q--) {
        int a,b; cin>>a>>b;
        a--, b--;
        int ln = (b-a+1)/2;
        mint h1 = SH.GetHash(a, a+ln);
        swap(a,b);
        a = N-a-1;
        b = N-b-1;
        ln = (b-a+1)/2;
        mint h2 = SH2.GetHash(a, a+ln);
        if(h1 == h2) cout<< "Yes"<<endl;
        else cout << "No" << endl;
    }
    return 0;
}