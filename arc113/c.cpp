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
    ll N; cin>>N;
    int l = 0;
    cout<<l<<endl;
    string s; cin>>s;
    if(s=="Vacant") return 0;
    bool lf = (s=="Male");
    int r = N;
    while(r-l > 1) {
        int c = (r+l)/2;
        bool ex;
        if((c-l)%2 == 0) ex=lf;
        else ex = !lf;
        cout<<c<<endl;
        cin>>s;
        if(s=="Vacant") return 0;
        bool cf = (s=="Male");
        if(cf==ex) {
            l=c;
            lf = cf;
        }
        else r=c;
    }
    return 0;
}