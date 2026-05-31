#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,Y,M;
    cin >> N >> Y >> M;
    ll ny = (M==12)?Y+1 : Y;
    ll nm = (M==12)?1 : M+1;
    ll sm1=0, sm2=0;
    rep(i,N) {
        ll a,b,p,q,c;
        cin>>a>>b>>p>>q>>c;
        if(p==ny && q==nm) sm2+=c;
        if(p==Y && q==M) sm1+=c;
    }
    cout<<sm1<< " "<<sm2<<endl;
    return 0;
}