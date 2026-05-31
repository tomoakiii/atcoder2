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
typedef pair<pair<int,int>,pair<int,int>> pii;
int main(){
    int N;
    cin>>N;
    vector<ll> X(N), Y(N);
    rep(i,N) {
         cin>>X[i]>>Y[i];
    }
    set<pii> st;
    rep(i,N) for(int j=i+1;j<N;j++){
             int a1,a2,b1,b2;
             if(X[i]==X[j]) {
                    a1=0; a2=0; b1=1; b2=X[i];
              } else if (Y[i]==Y[j]) {
                    a1=0; a2=1; b1=Y[i]; b2=1;
              } else {
                     ll dx=X[i]-X[j], dy=Y[i]-Y[j];
                     ll g=gcd(dx,dy);
                     a1=dy/g, a2=dx/g;
                     ll a1x=a1*X[i]-a2*Y[i];
                     ll g2=gcd(a1x, a2);
                     b1=a1x/g2, b2=a2/g2;
              }
              pii p = {{a1,a2},{b1,b2}};
              if(st.contains(p)) {
                      cout<<"Yes"<<endl;
                      return 0;
              }
              st.insert(p);
    }
    cout<<"No"<<endl;
    return 0;
}