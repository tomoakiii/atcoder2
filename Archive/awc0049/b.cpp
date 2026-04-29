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
    ll S,T,K;
    cin>>S>>T>>K;
    ll st=S;
    rep(i,K+1){
        if(st==T) {
            cout<<i<<endl;
            return 0;
        }
        st*=2;
        if(st>T) break;
    }
    cout<<-1<<endl;
    return 0;
}