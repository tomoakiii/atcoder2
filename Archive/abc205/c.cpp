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
    ll a,b,c; cin>>a>>b>>c;    
    if(c%2 == 0) c=2;
    else c=1;
    ll A = 1, B = 1; 
    rep(i,c) {
        A *= a;
        B *= b;
    }
    if(A<B) cout<<"<"<<endl;
    else if (A==B) cout<<"="<<endl;
    else cout<<">"<<endl;
    return 0;
}