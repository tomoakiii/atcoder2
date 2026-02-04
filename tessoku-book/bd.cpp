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
int main(){
    ll N,Q;
    string S;
    cin>>N>>Q>>S;
    mint d = 'z'-'a'+1;
    mint p = 1;
    vector<mint> hash(N+1);
    rep(i,N) {
        hash[i+1] = hash[i] + p * (S[i]-'a');
        p *= d;
    }
    vector<mint> pow(N+1,1);
    rep(i,N) {
        pow[i+1] = pow[i] * d;
    }
    vector<mint> rpow(N+1,1);
    rpow[N] = (mint)1/pow[N];
    for(int i=N; i>0; i--) {
        rpow[i-1] = rpow[i] * d;
    }
    while(Q--) {
        ll a,b,c,d; cin>>a>>b>>c>>d;
        mint h1 = hash[b] - hash[a-1];
        h1 *= rpow[a-1];
        mint h2 = hash[d] - hash[c-1];
        h2 *= rpow[c-1];
        if(h1 == h2) cout<< "Yes"<<endl;
        else cout << "No" << endl;
    }
    return 0;
}