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

int main(){
    ll N,Q;
    cin >> N >> Q;
    int M='z'-'a'+1;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    vector<int> A(Q), B(Q);
    dsu UF(M);
    vector<int> conv(M);
    rep(i,M) conv[i]=i;
    rep(i,Q) {
        char a,b; cin>>a>>b;
        int ia=a-'a', ib=b-'a';
        rep(j,M) if(conv[j]==ia) conv[j]=ib;
    }
    rep(i,N){
        for(auto c:S[i]) cout<<(char)(conv[c-'a']+'a');
        cout<<endl;
    }
    return 0;
}